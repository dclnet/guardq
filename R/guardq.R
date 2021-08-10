
myAdd <- function(a, b, r) {
  RES <- .C("myAdd2", A = as.integer(a), B = as.integer(b))
  RES$A
}

myTestPrint <- function(msg) {
  print(paste("<<<", msg, ">>>"))
}
