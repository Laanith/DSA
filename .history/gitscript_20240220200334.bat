@echo off
setlocal

rm -rf ./.history

set "targetFolder=D:\Code\DSA"

:DeleteFiles
for /r "%targetFolder%" %%F in (*.exe) do (
    echo Deleting "%%F"
    del "%%F" /q
)

endlocal

git add -A

git commit -m "Latest Commit"

git push -u origin main