param (
    [string]$searchTerm
)

if (-not $searchTerm) {
    $searchTerm = Read-Host "Enter your search term"
}

$searchTerm = $searchTerm -replace ' ', '+'
Start-Process "http://www.google.com/search?q=$searchTerm"
