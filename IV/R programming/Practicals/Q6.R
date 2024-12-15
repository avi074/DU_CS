library('stats')

nvars <- data.frame(n1 = rnorm(10, 10L, 10L),
                    n2 = rnorm(10, 100L, 100L))

bvars <- data.frame(b1 = rbinom(n = 100, size = 10L, p = .5),
                    b2 = rbinom(n = 100, size = 10L, p = .5))

cat("\nA.\n Correlation Coefficient : ", cor(bvars$b1, bvars$b2), '\n\n Summary :\n' )
print(summary(nvars))
cat('\n Data : \n')
str(nvars)

cat("\nB. Correlation Coefficient : ",cor(nvars$n1, nvars$n2, method = 'spearman'), '\n\n Summary :\n')
print(summary(bvars))
cat('\n Data : \n')
str(bvars)

par(mfrow = c(2,2))
plot(nvars, main = 'A. Random Normally Distributed Variables')
boxplot(nvars, col = c('red', 'green'))
hist(bvars$b1, main = 'B. Random Binomially Distributed Variables')
hist(bvars$b2)
