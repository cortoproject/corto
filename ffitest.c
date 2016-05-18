#include "ffi.h"
#include "stdio.h"
#include "stdlib.h"

void *foo(void* this, char* str, char* str2, void* obj) {
    printf("%p, %s, %s, %p\n", this, str, str2, obj);
    return obj;
}

ffi_cif* createcif() {
  ffi_cif *cif = malloc(sizeof(ffi_cif));
  ffi_type **args = malloc(sizeof(ffi_type*) * 4);
  args[0] = &ffi_type_pointer;
  args[1] = &ffi_type_pointer;
  args[2] = &ffi_type_pointer;
  args[3] = &ffi_type_pointer;

  ffi_prep_cif(
      cif,
      FFI_DEFAULT_ABI,
      4,
      &ffi_type_pointer,
      args);

  return cif;
}

int main(int argc, char* argv[]) {
    printf("Hello World\n");
    char *str1 = "foo";
    char *str2 = "bar";
    void *th = &str1;
    void *o = NULL;
    void *args[] = {&th, &str1, &str2, &o};
    void* result;
    ffi_cif *cif = createcif();

    ffi_call(cif, foo, &result, args);

    return 0;
}
