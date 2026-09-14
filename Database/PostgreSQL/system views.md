---
Author: Sumit Kumar
Email: ravirajkarn21@gmail.com
Date Created: 2026-08-20 08:46::18 AM
tags:
  - postgreSQL
  - Database
---
# System Views
|View Name|Purpose|
|---|---|
|[pg_indexes](https://www.postgresql.org/docs/8.0/view-pg-indexes.html)|indexes|
|[pg_locks](https://www.postgresql.org/docs/8.0/view-pg-locks.html)|currently held locks|
|[pg_rules](https://www.postgresql.org/docs/8.0/view-pg-rules.html)|rules|
|[pg_settings](https://www.postgresql.org/docs/8.0/view-pg-settings.html)|parameter settings|
|[pg_stats](https://www.postgresql.org/docs/8.0/view-pg-stats.html)|planner statistics|
|[pg_tables](https://www.postgresql.org/docs/8.0/view-pg-tables.html)|tables|
|[pg_user](https://www.postgresql.org/docs/8.0/view-pg-user.html)|database users|
|[pg_views](https://www.postgresql.org/docs/8.0/view-pg-views.html)|views|
```postgresql
SELECT * FROM pg_roles;
```
