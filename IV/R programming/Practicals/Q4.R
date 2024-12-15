library('MASS', 'ggpubr')
options(warn = -1)

attach(mammals)

pearson <- cor(x = mammals$body,
               y = mammals$brain,
               method = 'pearson')

spearman <- cor(x = mammals$body,
                y = mammals$brain,
                method = 'spearman')
cat(
  "\n\t\t\t Practical 4 \n\n\n A. Pearson & Spearman Correlation Coefficients\n",
  '\n\n Pearson Correlation Coefficient (cor)  \t : ',
  pearson,
  '\n\n Spearman Correltaion Coefficient (rho) \t : ',
  spearman,
  '\n\n Pearson & Spearman coefficients are equal ?\t : ',
  spearman == pearson,
  '\n\n Difference of Spearman & Pearson coefficients : ',
  spearman - pearson,
  '\n\n Any other Similarities : \n\t\t Both Correlation coefficients are showing a
        strong positive realtionship & association between
        Mammals\' Body & Brain !!!\n'
)

# B. Plotting the mammals data.frame
par(mfrow = c(2, 1))

plot(
  x = mammals$brain,
  y = mammals$body,
  xlab = 'Mammals\'s Brain',
  ylab = 'Mammals\' Body'
)

boxplot(
  x = mammals$brain,
  mammals$body,
  horizontal = TRUE,
  names = c('Brain', 'Body'),
  col = c('orange', 'dark green')
)

mtext(
  text = 'B. Plotting the values of \nMammals\' Brain v/s Mammals\' Body',
  outer = TRUE,
  col = 6,
  line = -3,
  font = 2
)


# C. Plotting the log values of mammals data.frame
plot(
  x = mammals$brain,
  y = mammals$body,
  xlab = 'Mammals\'s Brain',
  ylab = 'Mammals\' Body',
  log = 'xy'
)

boxplot(
  x = mammals$brain,
  mammals$body,
  horizontal = TRUE,
  names = c('Brain', 'Body'),
  col = c('orange', 'dark green'),
  log = 'x'
)

mtext(
  text = 'C. Plotting the logarithm values of \nMammals\' Brain v/s Mammals\' Body',
  outer = TRUE,
  col = 6,
  line = -3,
  font = 2
)

# Practice
plot.ts(mammals)
plot.ts(mammals, log = 'y')
