-- Keep a log of any SQL queries you execute as you solve the mystery.

-- took place on July 28, 2021 and on Humphrey Street.

--  -->> Get the police report related to the date

SELECT description FROM crime_scene_reports
WHERE year = 2021 AND month = 7 AND day = 28 AND street = "Humphrey Street";

-- ANSWER :
--Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery.
--Interviews were conducted today with three witnesses who were present at the time - each of their interview transcripts mentions the bakery.
--Littering took place at 16:36. No known witnesses.

--  -->> Get the witnesses report related to the time and mentioning bakery

SELECT name, transcript FROM interviews
WHERE transcript LIKE "%bakery%"
AND day = 28;

-- ANSWER :
--Ruth:
--Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away.
--If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.

--  -->> Get the list of license plate from the bakery security logs


--EUgene:
--I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery,
--I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.

--  -->> Get the account number from the ATM db
--  -->> Get the person id from the ban_acount db


--Raymond:
--As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call,
--I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow.
--The thief then asked the person on the other end of the phone to purchase the flight ticket.

--  -->> Get the number of caller and reciever (complice) (duration < 60 sec)
--  -->> Get the flight leaving the city the 29th
--  -->> Get the name of thief from list of passenger


--  -->> Get the flight leaving the city the 29th
--  -->> Get the list of Suspect from the license plate list from the bakery security logs
--  -->> Get the list of Suspect from the list of account number from the ATM db
--  -->> Get the list of Suspect from the list of person id from the ban_acount db
--  -->> Get the number of caller and reciever (complice) (duration < 60 sec)
--  -->> Get the name of thief from list of passenger


SELECT city FROM airports
WHERE id = (SELECT destination_airport_id FROM flights WHERE day = 29
AND origin_airport_id = (SELECT id FROM airports WHERE city = "Fiftyville") ORDER BY flights.hour) LIMIT 1;

SELECT name FROM people
WHERE license_plate IN (SELECT license_plate FROM bakery_security_logs
WHERE bakery_security_logs.year = 2021 AND bakery_security_logs.month = 7 AND bakery_security_logs.day = 28
AND bakery_security_logs.hour = 10 AND bakery_security_logs.minute > 15 AND bakery_security_logs.minute < (15+10) AND bakery_security_logs.activity = "exit")
INTERSECT
SELECT name FROM people
JOIN bank_accounts ON id = bank_accounts.person_id
WHERE account_number IN (SELECT account_number from atm_transactions
WHERE month = 7 AND day = 28 AND atm_location = "Leggett Street" AND transaction_type = "withdraw")
INTERSECT
SELECT name FROM people
JOIN phone_calls ON phone_number = phone_calls.caller
WHERE phone_calls.day = 28 AND phone_calls.duration < 60
INTERSECT
SELECT name FROM people
WHERE passport_number IN (SELECT passport_number FROM passengers
WHERE flight_id IN (SELECT id FROM flights WHERE destination_airport_id = 4 AND day = 29));

SELECT DISTINCT name FROM people
JOIN phone_calls ON phone_number = phone_calls.receiver
WHERE phone_calls.receiver = (
SELECT receiver FROM phone_calls
WHERE phone_calls.caller = (SELECT phone_number FROM people WHERE name = "Bruce")
AND phone_calls.day = 28 AND phone_calls.duration < 60);