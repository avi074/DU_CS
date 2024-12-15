library(DBI)

conn <- dbConnect(
  drv = RMySQL::MySQL(),
  dbname = 'dbms',
  user = 'avi',
  password = 'Avi@1407'
)

print(dbGetQuery(conn, 'show tables;'))

dbDisconnect(conn)
dbUnloadDriver(RMySQL::MySQL())
