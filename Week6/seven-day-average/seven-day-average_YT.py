import csv
import requests


def main():
    # Read NYTimes Covid Database
    download = requests.get(
        "https://raw.githubusercontent.com/nytimes/covid-19-data/master/us-states.csv"
    )
    decoded_content = download.content.decode("utf-8")
    file = decoded_content.splitlines()
    reader = csv.DictReader(file)

    # Construct 14 day lists of new cases for each states
    new_cases = calculate(reader)

    # Create a list to store selected states
    states = []
    print("Choose one or more states to view average COVID cases.")
    print("Press enter when done.\n")

    while True:
        state = input("State: ")
        if state in new_cases:
            states.append(state)
        if len(state) == 0:
            break

    print(f"\nSeven-Day Averages")

    # Print out 7-day averages for this week vs last week
    comparative_averages(new_cases, states)


# TODO: Create a dictionary to store 14 most recent days of new cases by state


def calculate(reader):
    new_cases = {}

    for row in reader:
        state = row["state"]
        date = row["date"]
        today_cases = int(row["cases"])

        if state not in new_cases:  # si un Etat n'est pas eu de cas recensé dans le dico Précédent
            new_cases[state] = []  # on crée une liste vide pour cet Etat qui n'est pas présent dans le dictionnaire précédent
        if len(new_cases[state]) >= 14:
            new_cases[state].pop(0)
        new_cases[state].append(today_cases)

    return new_cases

# TODO: Calculate and print out seven day average for given state


def comparative_averages(new_cases, states):
    for state in states:
        recent_cases = new_cases[state][7:]
        last_week_cases = new_cases[state][:7]
        average_recent = round(sum(recent_cases) / 7)
        average_last_week = round(sum(last_week_cases) / 7)

        diff = average_recent - average_last_week

        if diff > 0:
            msg = "an increase"
        else:

            msg = "a decrease"
        try:
            d = diff / average_last_week
            p = round(d * 100,2)
        except ZeroDivisionError:
            raise ZeroDivisionError

        print(f"{state} had a 7-day average of {diff} and {msg} of {p}%")


main()
