# CLIENT

Uses `methods` to acquire IP. Each `method` must present a consistent API on the backend and be interchangable.

## short term

* must be very fast
* supports script hooks for custom methods

## medium term

* supports adding custom servers for when they give consistant minimal output
  * for these cases, will dynamically strip away all HTTP & newlines, probably with regex.
  
## long term

* calibration feature, for logging the response times of each method

* in 'auto' mode, will silently try multiple methods to get public IP
  * must allow user to disable methods so they won't be selected for auto mode.
  * must use these logs to determine which method it queries first, to maximize responsiveness

# SERVER

Does nothing but spit out IP to any client that connects.

## short term

* must be very fast
* allows throttling or even blocking repeated requests to prevent server abuse
* support both HTTP and raw TCP connections, to maximize client-side simplicity.
* support secret key 
  * option to only permit requests via secret key
  * option to bypass throttling/blocking features with secret key

## med/long term

* crypto/ssl support to prevent replay attacks & AITM
