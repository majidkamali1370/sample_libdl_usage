#include <iostream>
#include <stdio.h>
#include <dlfcn.h>

using namespace std;

int main()
{
    const auto libfoo_handle = dlopen("libfoo.so", RTLD_NOW);

    if(!libfoo_handle)
    {
        cout << dlerror() << endl;
        dlclose(libfoo_handle);
        return 1;
    }

    const auto c_foo = dlsym(libfoo_handle, "c_foo");

    if(!c_foo)
    {
        cout << dlerror() << endl;
        dlclose(libfoo_handle);
        return 1;
    }

    const auto cpp_foo = dlsym(libfoo_handle, "_ZN2ns7cpp_fooEi");

    if(!cpp_foo)
    {
        cout << dlerror() << endl;
        dlclose(libfoo_handle);
        return 1;
    }

    using FooType = int(*)(int);

    cout << "Calling c_foo with value 100 -> " << FooType(c_foo)(100) << endl;
    cout << "Calling cpp_foo with value 100 -> " << FooType(cpp_foo)(100) << endl;

    dlclose(libfoo_handle);

    return 0;
}
