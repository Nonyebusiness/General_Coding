UPDATE shows
SET title = 'The ' || SUBSTR(title, 4)
WHERE title LIKE 'the %';
--this fixed all the "the's in the code
UPDATE shows
SET title = 'Avatar: The Last Airbender'
WHERE title LIKE 'Avatar%';

UPDATE shows
SET title = 'Community'
WHERE title LIKE 'c%';
--screwed up and ruined all the c titles

UPDATE shows
SET title = 'Cobra Kai'
WHERE id = 21;

UPDATE shows
SET title = 'Curb Your Enthusiasm'
WHERE id = 42;

UPDATE shows
SET title = 'Criminal Minds'
WHERE id = 54;

UPDATE shows
SET title = 'Criminal Minds'
WHERE id = 121;