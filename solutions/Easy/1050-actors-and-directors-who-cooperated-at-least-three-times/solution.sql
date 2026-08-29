-- ──────────────────────────────────────────────────
-- Problem  : 1050. Actors and Directors Who Cooperated At Least Three Times
-- Difficulty: Easy
-- Tags     : Database
-- Link     : https://leetcode.com/problems/actors-and-directors-who-cooperated-at-least-three-times/
-- Runtime  : 89 ms (beats 0%)
-- Memory   : 0B (beats 0%)
-- Language : mysql
-- Copyright: (c) 2026 YuvaUmayaShri. All rights reserved.
-- Synced by: leetie
-- ──────────────────────────────────────────────────

# Write your MySQL query statement below
SELECT actor_id, director_id
FROM ActorDirector
GROUP BY actor_id, director_id
HAVING COUNT(*) >= 3;