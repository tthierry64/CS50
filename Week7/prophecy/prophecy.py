#https://cs50.harvard.edu/x/2023/problems/7/prophecy/

# pour afficher un fichier .db et ainsi vérifier notre travail : télécharger : https://www.phpliteadmin.org/download/
# https://www.youtube.com/watch?v=S0mR_Gl7Rg4


# ce fichier est à utiliser en parallèle de : schema.sql

import csv
from cs50 import SQL

# functions
def create_house(house, houses, head):
    count = 0
    for h in houses:
        if h["house"] == house:
            count += 1
    if count == 0:
        houses.append({"house": house, "head": head})

def create_student(name, students):
    students.append({"student_name": name})

def create_relatioship(name, house, relationships):
    relationships.append({"student_name": name, "house": house})

#--------------------------------------------
# Main Programm

db = SQL("sqlite:///base.db")

students = []
houses = []
relationships = []

with open("students.csv", "r") as csvfile:
    reader = csv.DictReader(csvfile)
    for row in reader:
        name = row["student_name"]
        house = row["house"]
        head = row["head"]

        create_house(house, houses, head)
        create_student(name, students)
        create_relatioship(name, house, relationships)

for house in houses:
    db.execute("INSERT INTO houses (house, head) VALUES (?,?)", house["house"], house["head"])

for student in students:
    db.execute("INSERT INTO new_students (student_name) VALUES (?)", student["student_name"])

for rel in relationships:
    db.execute("INSERT INTO relationship (student_name, house) VALUES (?,?)", rel["student_name"], rel["house"])
