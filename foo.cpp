extern "C"
{

int c_foo(int v)
{
    return v * 10;
}

}

namespace ns {

int cpp_foo(int v)
{
    return v * 100;
}

}
