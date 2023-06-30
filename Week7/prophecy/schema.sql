-- ces lignes de code sont à exécuter en sqlite3 dans le terminal de commande du fichier roster.db
--# pour afficher un fichier .db et ainsi vérifier notre trvail : télécharger : https://www.phpliteadmin.org/download/
-- https://www.youtube.com/watch?v=nyq514Cp1SU


CREATE TABLE new_students(
    id INTEGER,
    student_name TEXT,
    PRIMARY KEY(id)
);

CREATE TABLE  houses(
    id INTEGER,
    house TEXT,
    head TEXT,
    PRIMARY KEY(id)
);

CREATE TABLE  relationship(
    id INTEGER,
    student_name TEXT,
    house TEXT,
    PRIMARY KEY(id)
);