#' Trend Plot
#' @author Avi
#' @description a function for plotting trend
#'

trendPlot <- function(t, yt, ...) {
  #Error Checking
  if (!is.vector(t) | !is.numeric(t))
    stop('t must be a numeric vector !!!')
  if (!is.vector(yt) | !is.numeric(yt))
    stop('yt must be a numeric vector !!!')
  if (length(t) != length(yt))
    stop('t & yt must be of same length !!!')

  #Calculations
  n = length(t)
  x <- t - mean(t)
  x.2 <- x ^ 2
  x.yt <- x * yt

  if (as.integer(sum(x)) != 0)
    stop('Please share more accurate data !!!')

  a = sum(yt) / n
  b = sum(x.yt) / sum(x.2)
  ye = a + b*x

  plot(
    x = t,
    y = yt,
    type = 'b',
    col = 'blue',
    lty = 'dashed',
    ylim = c(min(ye,yt), max(ye,yt))
  )
  lines(
    x = t,
    y = ye,
    type = 'o',
    col = 'red'
  )
  return(ye)
}
