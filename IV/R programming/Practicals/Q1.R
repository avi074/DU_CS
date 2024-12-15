library('stats')
options(warn = -1) #For disable any kind of warnings !!!

#a. Sampling of Normal Distribution with mean = 100 & S.D. = 5
x <- c(rnorm(100, mean = 100L, sd = 5L))
cat("\n\t\t Practical 1 \n\n A. Random Sample of Normal Distribution (x) :\n\n")
print(x)
cat('\n\n')

#b. Plotting of the Samples in a 3 * 2 matrix
par(mfrow = c(3, 2), col = 'black') # Matrix Designing
plot(x, ylab = "Samples", main = 'Point Plotting')
plot(x,
     ylab = "Samples",
     main = 'Line Plotting',
     type = 'l')
plot(x,
     ylab = "Samples",
     main = 'Points with Line Plotting',
     type = 'b')
plot(x,
     ylab = "Samples",
     main = 'Line without Points Plotting',
     type = 'c')
plot(x,
     ylab = "Samples",
     main = 'Stair Plotting',
     type = 's')
plot(x,
     ylab = "Samples",
     main = 'Histogram Plotting',
     type = 'h')
mtext(
  'B. Random Sample in Different Plots',
  line = -1.5 ,
  outer = TRUE,
  col = 6
)

#c. Hypothesis Testing for mean=100
result <- t.test(x, mu = 100)
print('C. Hypothesis testing for Mean = 100')
print(result)

#d. Wilcox Testing for mean=90
result <- wilcox.test(x, mu = 90)
print('D. Wilcox test for Mean/Location = 90')
print(result)