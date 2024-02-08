$filePath = "C:\Users\CRS\Desktop\test.txt"
$archivePath = "C:\Users\CRS\Desktop\Test.7z"
$password = "123"

# Create a new 7z archive with the specified password and add the file to it
& "C:\Program Files\7-Zip\7z.exe" a -t7z -mx9 -p"$password" $archivePath $filePath

# Check if the archive was created successfully before attempting to delete the original file
if (Test-Path $archivePath) {
    # Delete the original file
    Remove-Item -Path $filePath -Force

    Write-Host "File added to the password-protected 7z archive, and original file deleted successfully."
} else {
    Write-Host "Error: Archive creation failed. Original file not deleted."
}
