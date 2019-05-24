program matrixMultiplication
  implicit none
  integer, parameter :: n = 30000 ! Parameter N defining size of matrices
  real(kind=8),allocatable::m1(:,:),v1(:),v_res(:) ! Defining 1 matrix that will be allocatated in memory during executions
  ! plus two vectors
  integer(kind=4)::i, j, k ! Iterators
  real::start,finish ! Variables to make timing

allocate(m1(n,n),v1(n),v_res(n)) ! Alocating the matrices based on parameter n

! Filling up vpalues to matrix 1
do i = 1, n
 do j = 1, n
    m1(i, j) = i*i*1.7453+j*3.674528 ! This is a "random" operation in order not to allow the compiler taking advantage of the matrix value
  end do
end do

! Filling up values to matrix 2
do i = 1, n
    v1(i) = i*i*1.3569875*6.76512 ! This is a "random" operation in order not to allow the compiler taking advantage of the matrix value
end do

call cpu_time(start) ! Start timing
do i = 1, n
  do j = 1, n
      v_res(i) = v_res(i) + (m1(i,j) * v1(j))
  end do
end do
call cpu_time(finish) ! Finish timing
print '("Time to Row = ",f15.3," seconds. Started:",f6.3," - Finished:",f15.3,".")',finish-start,start,finish !Prints the time

call cpu_time(start) ! Start timing
do j = 1, n
  do i = 1, n
      v_res(i) = v_res(i) + (m1(i,j) * v1(j))
  end do
end do
call cpu_time(finish) ! Finish timing
print '("Time to Column = ",f15.3," seconds. Started:",f6.3," - Finished:",f15.3,".")',finish-start,start,finish !Prints the time

print*, 'Matrix Multiplication: Result Matrix' ! Show a result just to make sure...

print*, v_res(1), ' ' , v_res(2) , ' ' , v_res(3)

end program matrixMultiplication