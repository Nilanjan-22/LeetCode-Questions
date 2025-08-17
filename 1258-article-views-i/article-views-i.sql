# Write your MySQL query statement below
-- ALTER TABLE Views RENAME COLUMN author_id TO id;
SELECT DISTINCT author_id AS id FROM Views WHERE author_id=viewer_id ORDER BY id;