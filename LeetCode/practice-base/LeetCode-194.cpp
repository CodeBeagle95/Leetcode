# 转置文件
# Read from the file file.txt and print its transposed content to stdout.
column=$(cat file.txt | head -n1 | wc -w)
for i in $(seq 1 $column)
do
    awk '{print $'''$i'''}' file.txt | xargs
done