# distutils: language = c++
from PamplonaAndOliveiraModel cimport PamplonaAndOliveiraModel

def main():
    rec_ptr = new PamplonaAndOliveiraModel()
    try:
        rec_area = rec_ptr.retinalFlux(0.1,20)
    finally:
        del rec_ptr  # delete heap allocated object

    cdef PamplonaAndOliveiraModel rec_stack  # Instantiate a Rectangle object on the stack