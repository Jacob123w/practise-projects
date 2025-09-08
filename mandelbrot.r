Recursion_function <- function(Input_Number , Number_of_Recursions){
    Current_Iteration <- 0
    for (x in 1:Number_of_Recursions){
        Current_Iteration <- Current_Iteration^2 + Input_Number
    }
    return(Current_Iteration)
}

Check_Convergence <- function(Coordinate_x , Coordinate_y, Detail_Scalar){
    Complex_Number <- Coordinate_x + Coordinate_y*1i
    #Comparison <- (Mod(Recursion_function(Complex_Number, 10)^2 + Complex_Number) + 1)/(Mod(Recursion_function(Complex_Number, 10)) + 1)
    #if  (Comparison > 1){
    if (Mod(Recursion_function(Complex_Number, Detail_Scalar)) > 2){
        return(FALSE)
    } else{
        return(TRUE)
    }
}

Convergence.Area <- function(Step_Size, Detail_Scalar){
    y_Value <- -2
    x_Vector <- c()
    y_Vector <- c()

    while (y_Value <= 2){
        x_Value <- -2
        while (x_Value <= 2) {
            if (Check_Convergence(x_Value, y_Value, Detail_Scalar)) {
                x_Vector <- append(x_Vector, x_Value)
                y_Vector <- append(y_Vector, y_Value)
            }
            x_Value <- x_Value + Step_Size
        }
        y_Value <- y_Value + Step_Size
    }

    #plot(x_Vector, y_Vector, pch=20, asp=1, xlim=c(-2,2), ylim=c(-2,2), xlab="Re", ylab="Im")
    #grid()
    #abline(h = 0, v = 0, col = "red", lwd = 2)
}

Detail_Scalar_Vector <- 5:25
Time_Taken_Vector <- c(0)

for (x in 1:3) {
    Time_Taken_Vector_n <- c()
    for (i in 5:25) {
        start.time <- Sys.time()
        Convergence.Area(0.005, i)
        end.time <- Sys.time()
        print(end.time - start.time)
        Time_Taken_Vector_n <- append(Time_Taken_Vector, end.time - start.time)
    }
    Time_Taken_Vector <- Time_Taken_Vector + Time_Taken_Vector_n
    print("next")
}

Time_Taken_Vector <- Time_Taken_Vector / 3
plot(Detail_Scalar_Vector, Time_Taken_Vector, pch=20)
grid()
