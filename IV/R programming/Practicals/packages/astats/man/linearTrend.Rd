% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/linearTrend.R
\name{linearTrend}
\alias{linearTrend}
\title{Linear Trend}
\usage{
linearTrend(t, yt, ...)
}
\arguments{
\item{t}{A time vector from the time-series.}

\item{yt}{An entity data which is mapped according to t.}

\item{...}{Extra arguments that will be used in plot().}
}
\value{
ye A trend vector calculated from t & yt.
}
\description{
This function uses time-series data to create a linear trend line plot.
}
\examples{
linearTrend(t = c(1997:2002), yt = c(10,12,15,16,18,19))

}
\author{
Avi
}
