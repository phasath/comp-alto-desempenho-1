program matrixMultiplication
  implicit none
  integer, parameter :: n = 1600 ! Parameter N defining size of matrices
  real(kind=8),allocatable::m1(:,:),m2(:,:),m_res(:,:) ! Defining 3 matrices that will be allocatated in memory during executions
  integer(kind=4)::i, j, k ! Iterators
  real::start,finish ! Variables to make timing

allocate(m1(n,n),m2(n,n),m_res(n,n)) ! Alocating the matrices based on parameter n

! Filling up values to matrix 1
do i = 1, n
 do j = 1, n
    m1(i, j) = i*i*1.7453+j*3.674528 ! This is a "random" operation in order not to allow the compiler taking advantage of the matrix value
  end do
end do

! Filling up values to matrix 2
do i = 1, n
  do j = 1, n
    m2(i, j) = i*j*1.3569875*6.76512 ! This is a "random" operation in order not to allow the compiler taking advantage of the matrix value
  end do
end do

call cpu_time(start) ! Start timing
do i = 1, n
  do j = 1, n
    do k = 1, n
      m_res(i,j) = m_res(i,j) + (m1(i,k) * m2(k,j))
    end do
  end do
end do
call cpu_time(finish) ! Finish timing
print '("Time to Row = ",f15.3," seconds. Started:",f6.3," - Finished:",f15.3,".")',finish-start,start,finish !Prints the time

call cpu_time(start) ! Start timing
do j = 1, n
  do i = 1, n
    do k = 1, n
      m_res(i,j) = m_res(i,j) + (m1(i,k) * m2(k,j))
    end do
  end do
end do
call cpu_time(finish) ! Finish timing
print '("Time to Column = ",f15.3," seconds. Started:",f6.3," - Finished:",f15.3,".")',finish-start,start,finish !Prints the time

print*, 'Matrix Multiplication: Result Matrix' ! Show a result just to make sure...

print*, m_res(1, 1), ' ' , m_res(1, 2) , ' ' , m_res(1, 3)

end program matrixMultiplication