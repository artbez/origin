#pragma once

class MyError
{
public:
   class ExceptionOfAdding {};
   class ExceptionOfDeleting {};
   static void addingError() { throw ExceptionOfAdding(); }
   static void deletingError() { throw ExceptionOfDeleting(); }
};
