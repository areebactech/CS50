--Finding description from particular year, month and day.
SELECT description FROM crime_scene_reports
WHERE year = 2023 AND month = 7 AND day = 28
AND street = 'Humphrey Street';

--Overviewing interveiws.
SELECT transcript FROM interviews
WHERE year = 2023 AND month = 7 AND day = 28
AND transcript LIKE "%bakery%";

-- Checking the cars that left within 10 minutes after theft.
SELECT bakery_security_logs.activity, bakery_security_logs.license_plate, people.name FROM people
JOIN bakery_security_logs ON bakery_security_logs.license_plate = people.license_plate
WHERE bakery_security_logs.year = 2023
AND bakery_security_logs.month = 7
AND bakery_security_logs.day = 28
AND bakery_security_logs.hour = 10
AND bakery_security_logs.minute >= 15
AND bakery_security_logs.minute <= 25;
-- As a result, we have 8 suspects(Vanessa, Bruce, Barry, Luca, Sofia, Iman, Diana, Kelsey).

-- Checking ATM transactions history.
SELECT people.name, atm_transactions.transaction_type FROM people
JOIN bank_accounts ON bank_accounts.person_id = people.id
JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number
WHERE atm_transactions.year = 2023
AND atm_transactions.month = 7
AND atm_transactions.day = 28
AND atm_location = "Leggett Street"
AND atm_transactions.transaction_type = "withdraw";
-- As a result, again we have 8 suspects (Bruce, Diana, Luca, Iman, Brooke, Kenny, Taylor, Benista).

--Checking call logs.

UPDATE phone_calls
SET caller_name = people.name
FROM people
WHERE phone_calls.caller = people.phone_number;

UPDATE phone_calls
SET receiver_name = people.name
FROM people
WHERE phone_calls.receiver = people.phone_number;

SELECT caller, caller_name, receiver, receiver_name FROM phone_calls
WHERE year = 2023
AND month = 7
AND day = 28
AND duration < 60;

--Checking the city,where the theif went.

SELECT id,city
FROM airports
WHERE id = 4
OR id = 8
ORDER BY id DESC;

SELECT flights.destination_airport_id, name, phone_number, license_plate FROM people
JOIN passengers ON people.passport_number = passengers.passport_number
JOIN flights ON flights.id = passengers.flight_id
WHERE flights.id = 36
ORDER BY flights.hour ASC;

--Finding a common name from all tables.

SELECT name FROM people
JOIN passengers ON people.passport_number = passengers.passport_number
JOIN flights ON flights.id = passengers.flight_id
WHERE (flights.year = 2023 AND flights.month = 7 AND flights.day = 29 AND flights.id = 36)
AND name IN
(SELECT phone_calls.caller_name FROM phone_calls
WHERE year = 2023
AND month = 7
AND day = 28
AND duration < 60)
AND name IN
(SELECT people.name FROM people
JOIN bank_accounts ON bank_accounts.person_id = people.id
JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number
WHERE atm_transactions.year = 2023
AND atm_transactions.month = 7
AND atm_transactions.day = 28
AND atm_location = "Leggett Street"
AND atm_transactions.transaction_type = "withdraw")
AND name IN
(SELECT people.name FROM people
JOIN bakery_security_logs ON bakery_security_logs.license_plate = people.license_plate
WHERE bakery_security_logs.year = 2023
AND bakery_security_logs.month = 7
AND bakery_security_logs.day = 28
AND bakery_security_logs.hour = 10
AND bakery_security_logs.minute >= 15
AND bakery_security_logs.minute <= 25);

--Bruce is a common name in all tables and he called Robin when witness 3 watched him.
