cdef extern from "../src/PamplonaAndOliveiraModel.h":
    pass

# Decalre the class with cdef
cdef extern from "../src/PamplonaAndOliveiraModel.h" :
    cdef cppclass PamplonaAndOliveiraModel:
        PamplonaAndOliveiraModel() except +
		float retinalFlux(float lightIntensity, float pupilArea)