-- Keep a log of any SQL queries you execute as you solve the mystery.

--what data can i use
.table

.schema
--more data i supposes

.schema people
--wanted to look further into the peoples table

--to solve this case i have to find whwo the theif is, wwhere he escaped to, wwho helped him

--This occured on 28th of july, 2021 on Humphrey Street

.schema crime_scene_reports
--see what information is contain in crime scene reports

SELECT * FROM crime_scene_reports WHERE street = 'Humphrey Street' AND year = 2021 AND month = 7 AND day = 28;
--this let me see crimes on the informaiton given to me

-- the id of the crime descripted to me for the crime is porbably 295
--crime id 295 | 295 | 2021 | 7     | 28  | Humphrey Street | Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery. Interviews were conducted today with three witnesses who were present at the time – each of their interview transcripts mentions the bakery.
--the crime scene report says their interview transscripts mentions a bakery

.tables --wanted to see my next options, there are interviews which may have id 295 which mayg ive more clues

.scheme interviews
--wanted to see how to interact with the interviews table

SELECT * FROM interviews WHERE year = 2021 AND month = 7 AND day = 28;
--was looking for interviews on that day
--ruth, raymond and eugene wereat the
--ruth within 10 mins of robbery theif in car in barkey parking lot drive away, security footage from bakery parking lot might have it, look at cars that left within that timeframe
--eugene doesn't know theifs name, someone he recognised, theif was withdrawing money from atm on legget street, saw theif withdrawing money
-- raymond as theif left bakey, they called someone for less than a minute, he heard theif say that they were taking the earliest flight out of fiftyvill tomorrow, asked other person to purchase the fligt tichet
--main take aways, check look for earliest flight out fiftyvill on 29 7 2021
-- look at bakey parking
--earlier in the mornin before eugene went to the bakey, he walked by a atm on legget str and saw the theif withdrawing money

.tables
--wanted to look at tables

.schema bakery_security_logs
--wanted to see bakery security logs

 SELECT * FROM bakery_security_logs WHERE day = 28 AND month = 7 AND year = 2021;
 --checking security logs on that day
 --deadend can't figure much out dont know the exact time

 .schema atm_transactions
 --decided to look at atm transactions
 SELECT * FROM atm_transactions WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw';
 --nothing useful no time or data or names

 .schema flights
 --moving onto flights
 SELECT * FROM flights WHERE year = 2021 AND month = 7 AND day = 29;

 --this is a day from the 28th and the sooners flighjt is hour 8 minute 20 with deistination id = 4

SELECT * FROM airports WHERE id = 4;
--looked at what i could find about where they left, they went to newyork city to laguardia airport


SELECT * FROM crime_scene_reports WHERE street = 'Humphrey Street';
--decided to look back here to see what anything i missed
--i missed the fact the robbery took place at 10:15am, now i know within 10 minutes of that time frame the robber left

SELECT * FROM bakery_security_logs WHERE day = 28 AND month = 7 AND year = 2021 AND activity = 'exit';

-- 261 | 2021 | 7     | 28  | 10   | 18     | exit     | 94KL13X       |
--| 262 | 2021 | 7     | 28  | 10   | 18     | exit     | 6P58WS2       |
--| 263 | 2021 | 7     | 28  | 10   | 19     | exit     | 4328GD8       |
--| 264 | 2021 | 7     | 28  | 10   | 20     | exit     | G412CB7       |
--| 265 | 2021 | 7     | 28  | 10   | 21     | exit     | L93JTIZ       |
--| 266 | 2021 | 7     | 28  | 10   | 23     | exit     | 322W7JE       |
--| 267 | 2021 | 7     | 28  | 10   | 23     | exit     | 0NTHK55

--all possible lisence plates

SELECT * FROM atm_transactions WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = 'Leggett Street' AND transaction_type = 'withdraw';
--wanted to look at this again to see if i get any new ideas

 SELECT p.name, bsl.activity, bsl.license_plate, bsl.year, bsl.month, bsl.day, bsl.hour, bsl.minute
 FROM bakery_security_logs bsl
 JOIN people p ON p.license_plate = bsl.license_plate
 WHERE bsl.year = 2021 AND bsl.month = 7 AND bsl.day = 28 and bsl.hour = 10 AND bsl.minute BETWEEN 15 AND 25;
 --would let me see who left the bakey around the time that the witness described

 SELECT a.*, p.name
 FROM atm_transactions a
 JOIN bank_accounts b ON a.account_number = b.account_number
 JOIN people p ON b.person_id = p.id
 WHERE a.atm_location = 'Leggett Street' AND a.year = 2021 AND a.month = 7 AND a.day = 28 AND a.transaction_type = 'withdraw';
 --shows me people who withdrew on that same day

 --many people do collide like Bruce, IMan, Luca

 SELECT * FROM interviews WHERE year = 2021 AND month = 7 AND day = 28;
 --looked at this again cause im stuck
--saw that the thief did call someone for less than a minute

SELECT * FROM phone_calls WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60;
--with the phone numbers of the caller we can see the names and try match it up with the other names


SELECT p.name, pc.caller, pc.receiver, pc.year, pc.month, pc.day, pc.duration
FROM phone_calls pc
JOIN people p ON pc.caller = p.phone_number
WHERE pc.year = 2021 AND pc.month = 7 AND pc.day = 28 AND pc.duration < 60;

--gave a list of callers and names


Phone list
Sofia
Kesley
Bruce
Kesley
Taylor
Diana
Carina
Kenny
Benista

Security footage list:
Vannessa
Bruce
Barry
Luca
Sofia
Iman
Diana
Kesley


after manually comapring here is list of people in both security and phone list
bruce
diana
kesley
sofia



ATM LIST
Bruce
Diana
Brooke
Kenny
Iman
Luca
Taylor
Benista

aftering comparing that last list with atm list here is new list
bruce
diana

still two people that it could be
will narrow down based on flight

 SELECT * FROM flights WHERE year = 2021 AND month = 7 AND day = 29;

SELECT p.name
FROM people p
JOIN passengers ps ON p.passport_number = ps.passport_number
WHERE ps.flight_id = 36
AND p.name IN ('Bruce', 'Diana');

This returned bruce only so bruce is the thief
to find accomplice look at who bruce called

SELECT p.name, pc.caller, pc.receiver, pc.year, pc.month, pc.day, pc.duration
FROM phone_calls pc
JOIN people p ON pc.caller = p.phone_number
WHERE pc.year = 2021 AND pc.month = 7 AND pc.day = 28 AND pc.duration < 60;

Bruce called this number (375) 555-8161, so find the person based on this number

SELECT name, phone_number FROM people WHERE phone_number = '(375) 555-8161';

it's robin oh wait this is batman i just realised