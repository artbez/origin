#pragma once

class MyError
{
public:
   class ExceptionOfDeleting {};
   /// Exception of deleting in queue with priority
   static void deletingError() { throw ExceptionOfDeleting(); }
};
