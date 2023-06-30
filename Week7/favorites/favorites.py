from cs50 import SQL

db = SQL("sqlite:///favorites.db")

titles = db.execute("SELECT title FROM shows")

for title in titles:
    print('Titre : {}'.format(titles[0]))

#if titles['title'] == "'Avatar'":
#    titles['title'] == "'Nique ta mère enculé je vais tout déchirer'"