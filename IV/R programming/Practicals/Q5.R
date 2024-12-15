library('MASS')

attach(UScereal)

# A. Relation of Manufacturer & Shelf
plot(
  x = UScereal$mfr,
  y = UScereal$shelf,
  xlab = 'Manufacturer',
  ylab = 'Shelf',
  main = 'A. Relation of Manufacturer & Shelf of UScereal',
  col = c(3:7)
)

# B. Relation of Fat & Vitamins
plot(
  x = UScereal$vitamins,
  y = UScereal$fat,
  xlab = 'Vitamins',
  ylab = 'Fat',
  main = 'B. Relation of Fat & Vitamins of UScereal',
  col = 'purple'
)

# C. Relation of Fat & Shelf
boxplot(
  x = UScereal$fat,
  UScereal$shelf,
  names = c('Fat', 'Shelf'),
  main = 'C. Relation of Fat & Shelf of UScereal',
  col = c('orange','brown'),
  horizontal = TRUE,
  xlab = 'Range of Values'
)

# D. Relation of Carbohydrates & Sugars
plot(
  x = UScereal$carbo,
  y = UScereal$sugars,
  xlab = 'Carbs',
  ylab = 'Sugars',
  main = 'D. Relation of Carbohydrates & Sugars of UScereal',
  col = 'dark green'
)

# E. Relation of Manufacturer & Fibre
plot(
  x = UScereal$mfr,
  y = UScereal$fibre,
  xlab = 'Manufacturer',
  ylab = 'Fibre',
  main = 'E. Relation of Manufacturer & Fibre of UScereal',
  col = c(3:8)
)

# F. Relation of Sodium & Sugars
plot(
  x = UScereal$carbo,
  y = UScereal$sugars,
  xlab = 'Sodium',
  ylab = 'Sugars',
  main = 'F. Relation of Sodium & Sugars of UScereal',
  col = 'dark blue'
)