# Data set scaling functions

*"Most of the times, your dataset will contain features highly varying in magnitudes, units and range. ... we need to bring all features to the same level of magnitudes. This can be achieved by scaling."*

See: [scaling](https://medium.com/greyatom/why-how-and-when-to-scale-your-features-4b30ab09db5e).

## meanNormalisation

- a data set has an actual mean value *mean(xActual)*
- the mean value should become 0 by mean normalisation *mean(xTarget) = 0*
<br>
- *xTarget = (xActual - mean(xActual)) / (max(xActual) - min(xActual))*

The set of *xTarget* values will have values between *-1* and *1*:

- *-1 <= xTarget <= 1*
<br>
- *min(xTarget) >= -1*

- *max(xTarget) <= 1*

## minmaxScaling

- a data set has values between *minActual* and *maxActual*.
- the data values must be scaled between the range *minTarget* and *maxTarget*.

Solve **A** (scaling) and **B** (offset) by solving 2 equations:

- *minTarget = A \* minActual + B*

- *maxTarget = A * maxActual + B*

First step eliminate **B** to find **A**:

- *minTarget - maxTarget = A \* (minActual - maxActual)*
<br>
- *A = (minTarget - maxTarget) / (minActual - maxActual)*

Second step find **B** using **A**:

- *B = minTarget - (A \* minActual)*
