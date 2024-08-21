rm -recurse -force .history

(Get-ChildItem -Recurse -Filter *.cpp | Measure-Object).Count