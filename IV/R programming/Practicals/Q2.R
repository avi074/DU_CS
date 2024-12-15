library('DMwR2')
options(warn = -1)

#import & set up database for user
attach(algae)
#fix(algae)

color = c('red', 'green', 'orange', 'blue')

#A. Plotting a multiple graph to show the distribution of algae a6
par(mfrow = c(2, 2)) #plot graphs in a grid

plot(
  x = algae$a6,
  xlab = 'Index',
  ylab = 'algae a6',
  type = 'l'
)

plot(
  x = algae$season,
  y = algae$a6,
  xlab = 'Season',
  ylab = 'algae a6',
  col = color
)

plot(
  x = algae$size,
  y = algae$a6,
  xlab = 'River Size',
  ylab = 'algae a6',
  col = color
)

plot(
  x = algae$speed,
  y = algae$a6,
  xlab = 'River Speed',
  ylab = 'algae a6',
  col = color
)

mtext(
  text = 'A. Graph of distribution of Algae a6',
  line = -2,
  outer = TRUE,
  col = 'dark blue',
  font = 2,
  cex = 1.5
)

#B. Showing the distribution of values of size = 3
algae.size3 <- algae[algae$size == 'small', ]
cat('\nB. Distribution of Algae values for size = 3\n')
str(algae.size3)

#c. Checking visually that algae$oPO4 is normally distributed or not
par(mfrow = c(1, 2))

boxplot(x = algae$oPO4,
        ylab = 'algae$oPO4')
mtext(text = 'Here,\n Values evenly distributed\t: No\n Median is in centre\t\t: No\n Normally Distributed\t\t: No',
      side = 1,
      line = 4)

hist(x = algae$oPO4,
     main = '')
mtext(
  text = 'Here,\n Bell-shaped Histogram : No\n Normally Distributed : No',
  adj = 1,
  line = -3
)

mtext(
  text = 'C. Visual Normality Check of Algae oPO4',
  line = -2,
  outer = TRUE,
  col = 6,
  font = 2,
  cex = 1.5
)

# D. NO3 distribution regarding river size
par(mfrow = c(1, 1))

plot(
  x = algae$size,
  y = algae$NO3,
  xlab = 'River Size',
  ylab = 'algae NO3',
  col = color
)

mtext(
  text = 'D. NO3 Distribution across River Sizes',
  line = -2,
  outer = TRUE,
  col = 6,
  font = 2,
  cex = 1.2
)

# E. Algae A1 distribution across River Speed
plot(
  x = algae$speed,
  y = algae$a1,
  xlab = 'River Speed',
  ylab = 'Algae a1',
  col = color
)

mtext(
  text = 'E. Algae A1 distribution across River Speed',
  line = -2,
  outer = TRUE,
  col = 20,
  font = 2,
  cex = 1.2
)

# F. Algae A1 relationship with Algae A6
par(mfrow = c(2,1))

plot(
  x = algae$a1,
  y = algae$a6,
  xlab = 'Algae a1',
  ylab = 'Algae a6',
)

boxplot(
  x = algae$a1,algae$a6,
  horizontal = TRUE,
  names = c('Algae a1', 'Algae a6'),
  col = color[2:3]
)

mtext(
  text = 'F. Relationship of Algae A1 with Algae A6',
  line = -2,
  outer = TRUE,
  col = 20,
  cex = 1.2
)