#' Linear Trend
#'
#' This function uses time-series data to create a linear trend line plot.
#'
#' @author Avi
#' @param t  A time vector from the time-series.
#' @param yt An entity data which is mapped according to t.
#' @return ye A trend vector calculated from t & yt.
#'
#'
#' @export
#' @examples
#' linearTrend(t = c(1997:2002), yt = c(10,12,15,16,18,19))
#'

linearTrend <- function(t, yt, ...) {
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
    ylim = c(min(ye,yt), max(ye,yt)),
    ...
  )
  lines(
    x = t,
    y = ye,
    type = 'o',
    col = 'red'
  )
  return(ye)
}
