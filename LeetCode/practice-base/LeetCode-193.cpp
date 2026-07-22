# 有效的电话号码 - (xxx) xxx-xxxx 或 xxx-xxx-xxxx
# Read from the file file.txt and output all valid phone numbers to stdout.
grep -P '^([0-9]{3}-|\([0-9]{3}\) )[0-9]{3}-[0-9]{4}$' file.txt