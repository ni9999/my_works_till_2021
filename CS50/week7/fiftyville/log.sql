-- Keep a log of any SQL queries you execute as you solve the mystery.
.schema;
.tables;
.schema crime_scene_reports;
SELECT * FROM crime_scene_reports;
--to know the id
SELECT * FROM crime_scene_reports WHERE street = "Chamberlin Street";
--the id is 295. got some cool information
--description - Theft of the CS50 duck took place at 10:15am at the Chamberlin Street courthouse. Interviews were conducted today with three witnesses who were present at the time — each of their interview transcripts mentions the courthouse.
SELECT * FROM crime_scene_reports WHERE street = "Chamberlin Street" AND month = 7 AND day = 28;
--wanna see what is in the courthouse
.schema courthouse_security_logs
--thinking that using previous id is enough 
sqlite> SELECT * FROM courthouse_security_logs WHERE id = 295;
--that id didn't work. seems this id is meaningless. Working manually  
sqlite> SELECT * FROM courthouse_security_logs WHERE day = 28 AND hour = 10 AND minute = 15;
sqlite> SELECT * FROM courthouse_security_logs WHERE day = 28 AND hour = 10;
--very interesting output  
--10|14|entrance|13FNH73
--10|16|exit|5P2BI95
--AND the theft happened in 10:15.this can be suspect but the license-plate are not same
sqlite> .schema passengers 
sqlite> .schema people 
-- got license_plate. wanna see who came and go at that time
sqlite> SELECT * FROM people WHERE license_plate = "13FNH73" OR license_plate = "5P2BI95";
-- got two suspects
--221103|Patrick|(725) 555-4692|2963008352|5P2BI95
--745650|Sophia|(027) 555-1068|3642612721|13FNH73
--probably either patrick or sophia
--we got phone number and passport number and name 
--looking to schema to know where can i relate
sqlite> SELECT * FROM interviews WHERE name = "Patrick" OR name = "Sophia"; 
-- looks like it won't help interviews was in January  or February. No recent
-- lets see if i can do anything with bank_account table - there is a person_id. 
sqlite> SELECT * FROM bank_accounts WHERE person_id = 221103 OR person_id = 745650;
sqlite> SELECT * FROM bank_accounts WHERE person_id = 221103;
sqlite> SELECT * FROM bank_accounts WHERE person_id = 745650;
--this has a return
--42445987|745650|2011
--that means Sophia has a bank account
--I am confused where to go 
sqlite> SELECT * FROM passengers WHERE passport_number = 2963008352;
sqlite> SELECT * FROM passengers WHERE passport_number = 3642612721;
--just doing it because there is a passport_id
--seems both has travelled 
--so it will not help
sqlite> SELECT * FROM phone_calls
--to see what caller text means
--it is phone number 
--finding if sophia and patric has any connection
sqlite> SELECT * FROM phone_calls WHERE caller = "(725) 555-4692" OR receiver = "(725) 555-4692" OR caller = "(027) 555-1068" OR receiver = "(027) 555-1068";
--sophia and patrick does not have any phone calls
--found something more interesting
--257|(725) 555-4692|(821) 555-5262|2020|7|28|456
--seems patrick has done some connection on 28 July 
--who is this
sqlite> SELECT * FROM people WHERE phone_number = "(821) 555-5262";
--632023|Amanda|(821) 555-5262|1618186613|RS7I6A0
--this is amanda
--Seeing amanda's interview
sqlite> SELECT * FROM interviews WHERE name = "Amanda";
--interesting
--180|Amanda|2020|8|19|“You want to go home, no doubt, Doctor,” he remarked as we emerged.
--seeing if she has any flight
sqlite> SELECT * FROM passengers WHERE passport_number= "1618186613";
-- 3 flights.
--no-6 flight also taken by sophia
--need some flight information
sqlite> SELECT * FROM flights WHERE id = 6;
--6|8|5|2020|7|28|13|49
--the flight was taken 28 July 
--wanna know from where to where
sqlite> SELECT * FROM airports WHERE id = 5 OR id = 8;
--The flight was from 8= Fiftyville to 5= Dallas
--I am just thinking that Amanda is the thief and patrick(before theft) and sophia(after theft) is helping. not sure
sqlite> SELECT * FROM flights;
--wanna know how they are ordered
sqlite> SELECT * FROM flights ORDER BY date;
--just wanted to see how many flights in 28 July
--ok. probably i should have all the informations about Amanda which i know about patrick or sophia
-- first is license_plate in the courthouse
sqlite> SELECT * FROM courthouse_security_logs WHERE license_plate = "RS7I6A0";
--he was there in 25 July and 28 July
--277|2020|7|28|13|8|entrance|RS7I6A0
--281|2020|7|28|15|6|exit|RS7I6A0
--HOW she entered courthouse at 13:08 and exited at 15:06 and taken flight at 13:49
--that means definitely she was not in her car 
--okey. I didn't checked the same for patrick and sophia
sqlite> SELECT * FROM courthouse_security_logs WHERE license_plate = "5P2BI95";
--patrick
255|2020|7|28|9|15|entrance|5P2BI95
260|2020|7|28|10|16|exit|5P2BI95
sqlite> SELECT * FROM courthouse_security_logs WHERE license_plate = "13FNH73";
--sophia
169|2020|7|27|11|11|entrance|13FNH73
187|2020|7|27|13|25|exit|13FNH73
259|2020|7|28|10|14|entrance|13FNH73
288|2020|7|28|17|15|exit|13FNH73
320|2020|7|29|12|49|entrance|13FNH73
335|2020|7|29|16|20|exit|13FNH73
357|2020|7|30|9|12|entrance|13FNH73
420|2020|7|30|16|5|exit|13FNH73
--seems sophia regularly visits in courthouse 
--thought i did missed something. so decided to see the crime_scenereport again
sqlite> SELECT * FROM crime_scene_reports WHERE street = "Chamberlin Street";
-- oh there is a mention of interviews
sqlite> SELECT * FROM interviews WHERE transcript LIKE "%CS50%"; 
sqlite> SELECT * FROM interviews WHERE transcript LIKE "%CS50%"; 
sqlite> SELECT * FROM interviews WHERE transcript LIKE "%courthouse%"; 
-- oh my god. why i did not thougt about it the interviews. seems i was at wrong place
--161|Ruth|2020|7|28|Sometime within ten minutes of the theft, I saw the thief get into a car in the courthouse parking lot and drive away. If you have security footage from the courthouse parking lot, you might want to look for cars that left the parking lot in that time frame.
--162|Eugene|2020|7|28|I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at the courthouse, I was walking by the ATM on Fifer Street and saw the thief there withdrawing some money.
--163|Raymond|2020|7|28|As the thief was leaving the courthouse, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket.
--I think doing works on these 3 will make the case easier
sqlite> SELECT license_plate FROM courthouse_security_logs WHERE month = 7 AND day = 28 AND hour = 10 AND minute >= 15 AND minute <= 25;
sqlite> SELECT * FROM courthouse_security_logs WHERE month = 7 AND day = 28 AND hour = 10 AND minute >= 15 AND minute <= 25;
--they exited. for sure they are the suspect need more information
5P2BI95
94KL13X
6P58WS2
4328GD8
G412CB7
L93JTIZ
322W7JE
0NTHK55
SELECT * FROM people WHERE license_plate IN (SELECT license_plate FROM courthouse_security_logs WHERE month = 7 AND day = 28 AND hour = 10 AND minute >= 15 AND minute <= 25);
--gotcha 
221103|Patrick|(725) 555-4692|2963008352|5P2BI95
243696|Amber|(301) 555-4174|7526138472|6P58WS2
396669|Elizabeth|(829) 555-5269|7049073643|L93JTIZ
398010|Roger|(130) 555-0289|1695452385|G412CB7
467400|Danielle|(389) 555-5198|8496433585|4328GD8
514354|Russell|(770) 555-1861|3592750733|322W7JE
560886|Evelyn|(499) 555-9472|8294398571|0NTHK55
686048|Ernest|(367) 555-5533|5773159633|94KL13X

sqlite> SELECT * FROM atm_transactions;
-- just to see how is the data
sqlite> SELECT * FROM atm_transactions WHERE atm_location = "Fifer Street" AND day = 28 AND month = 7 AND transaction_type = "withdraw";
-- got some account number
-- let us find the common persons
sqlite> SELECT * FROM people WHERE license_plate IN (SELECT license_plate FROM courthouse_security_logs WHERE month = 7 AND day = 28 AND hour = 10 AND minute >= 15 AND minute <= 25) AND id IN (SELECT person_id FROM bank_accounts WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE atm_location = "Fifer Street" AND day = 28 AND month = 7 AND transaction_type = "withdraw"));
--gocha they are the suspect 
396669|Elizabeth|(829) 555-5269|7049073643|L93JTIZ
467400|Danielle|(389) 555-5198|8496433585|4328GD8
514354|Russell|(770) 555-1861|3592750733|322W7JE
686048|Ernest|(367) 555-5533|5773159633|94KL13X
--at 29 july the first out plane of fiftyville there is the thief
sqlite> SELECT id FROM airports WHERE city = "Fiftyville";
sqlite> SELECT * FROM flights WHERE origin_airport_id = (SELECT id FROM airports WHERE city = "Fiftyville") AND month = 7 AND day = 29;
18|8|6|2020|7|29|16|0
23|8|11|2020|7|29|12|15
36|8|4|2020|7|29|8|20
43|8|1|2020|7|29|9|30
53|8|9|2020|7|29|15|20
-- ok seems 36 - id flight is the earliest
-- lets find the thief
sqlite> SELECT * FROM people WHERE license_plate IN (SELECT license_plate FROM courthouse_security_logs WHERE month = 7 AND day = 28 AND hour = 10 AND minute >= 15 AND minute <= 25) AND id IN (SELECT person_id FROM bank_accounts WHERE account_number IN (SELECT account_number FROM atm_transactions WHERE atm_location = "Fifer Street" AND day = 28 AND month = 7 AND transaction_type = "withdraw")) AND passport_number IN (SELECT passport_number FROM passengers WHERE flight_id = 36);
-- gocha
467400|Danielle|(389) 555-5198|8496433585|4328GD8
686048|Ernest|(367) 555-5533|5773159633|94KL13X
-- according to raymond the thief was talking over phone in 10:15 to 10:25 for less than a minute
sqlite> SELECT * FROM phone_calls WHERE month = 7 AND day = 28 AND duration <60;
--got the thief;
--233|(367) 555-5533|(375) 555-8161|2020|7|28|45
--matching the phone numbers Ernest is the thief
-- lets see where he escaped
sqlite> SELECT * FROM flights WHERE id IN (SELECT flight_id FROM passengers WHERE passport_number = 5773159633);
-- ok just 36 - id flight 
36|8|4|2020|7|29|8|20
-- he escaped in 4
-- where is 4
sqlite> SELECT * FROM airports WHERE id = 4;
-- 4|LHR|Heathrow Airport|London
--he is here
-- Ernest talked to (375) 555-8161 this number. this must be accompliance
sqlite> SELECT * FROM people WHERE phone_number = "(375) 555-8161";
-- 864400|Berthold|(375) 555-8161||4V16VO0
--this is berthold





























