# distutils: language = c++

from PamplonaAndOliveiraModel cimport PamplonaAndOliveiraModel

# Create a Cython extension type which holds a C++ instance
# as an attribute and create a bunch of forwarding methods
# Python extension type.
cdef class PyPamplonaAndOliveiraModel:
    cdef PamplonaAndOliveiraModel c_rect  # Hold a C++ instance which we're wrapping

    def __cinit__(self):
        self.c_rect = PamplonaAndOliveiraModel()

	def retinalFlux(self,float lightIntensity, float pupilArea)
		return self.c_rect.retinalFlux(lightIntensity,pupilArea)