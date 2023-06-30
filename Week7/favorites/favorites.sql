from cs50 import SQL
db = SQL("sqlite://favorites.db")

titles = db.execute("SELECT title FROM shows")

for title in titles
