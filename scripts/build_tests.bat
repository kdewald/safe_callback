@echo off
powershell.exe -NoProfile -ExecutionPolicy Bypass "& {& '%~dp0build_tests.ps1' %*}"