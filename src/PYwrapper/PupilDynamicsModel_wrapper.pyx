#This is a Cython file and extracts the relevant classes from the C++ header file.

# distutils: language = c++

from libcpp.string cimport string
from libcpp cimport bool

cdef extern from "../PupilDynamicsModel.h":
    cdef cppclass PupilDynamicsModel:
        PupilDynamicsModel(string) except + 
        float pupilDiameterAt(float)
        float pupilDiameterAt(float,float,float)
        string getName()
        bool isInLumens()
        string name

cdef extern from "../DegrootAndGebhardModel.h":
    cdef cppclass DegrootAndGebhardModel(PupilDynamicsModel):
        DegrootAndGebhardModel() except +
        float pupilDiameterAt(float)
        bool isInLumens()
        string name
        float pupilDiameterWithMillilamberts(float)
        

cdef class PyPupilDynamicsModel:
    cdef PupilDynamicsModel *base      # hold a C++ instance which we're wrapping
    def __cinit__(self, string name):
        self.base = new PupilDynamicsModel(name.encode('utf-8'))
    def __dealloc__(self):
        del self.base
    def getName(self):
        return self.base.getName()
    def isInLumens(self):
        return self.base.isInLumens()
    def pupilDiameterAt(self,float lightIntensity):
        return self.base.pupilDiameterAt( lightIntensity)
    def pupilDiameterAt(self,float lightIntensity,float latency,float time):
        return self.base.pupilDiameterAt(lightIntensity,latency,time)

cdef class PyDegrootAndGebhardModel(PyPupilDynamicsModel):
    cdef DegrootAndGebhardModel*thisptr
    def __cinit__(self):
        self.thisptr = new DegrootAndGebhardModel()
    def __dealloc__(self):
        del self.thisptr
    def getName(self):
        return self.thisptr.getName()
    def isInLumens(self):
        return self.base.isInLumens()
    def pupilDiameterAt(self,float lightIntensity):
        return self.thisptr.pupilDiameterAt(lightIntensity)
    def pupilDiameterWithMillilamberts(self,float lightIntensity):
        return self.thisptr.pupilDiameterWithMillilamberts(lightIntensity)
