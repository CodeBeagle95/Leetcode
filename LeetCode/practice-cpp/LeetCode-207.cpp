// 课程表 深度优先
class Solution {
private:
    unordered_map<int, unordered_set<int>> courseGraph_;
    unordered_set<int> learningCourseSet_;
    unordered_set<int> learnedCourseSet_;

    bool dfs(int course) {
        if (learningCourseSet_.find(course) != learningCourseSet_.end()) {
            return false;                      // 重入学习中课程，返回 false
        }
        if (learnedCourseSet_.find(course) != learnedCourseSet_.end()) {
            return true;                       // 已学习课程直接返回 true
        }
        auto found = courseGraph_.find(course);
        if (found == courseGraph_.end()) {
            learnedCourseSet_.insert(course);  // 没有依赖直接加入已学习课程
            return true;
        }
        
        learningCourseSet_.insert(course);
        for (auto& nextCourse : found->second) {
            if (!dfs(nextCourse)) {
                return false;
            }
        }
        learningCourseSet_.erase(course);  // 移除学习中课程
        learnedCourseSet_.insert(course);  // 依赖后加入课程全部学习完加入已学习课程
        return true;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for (auto& p : prerequisites) {
            if (p.size() != 2) continue;
            courseGraph_[p[0]].insert(p[1]);
        }

        for (int course = 0; course < numCourses; ++course) {
            if (!dfs(course)) {
                return false;
            }
        }
        return true;
    }
};
