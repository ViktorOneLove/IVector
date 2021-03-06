#pragma once
#include <cstddef>
#include "RC.h"

class Logger;

class IVector {
public:
    enum NORM {
        Infinite,
        First,
        Second
    };

    static IVector* createVector(size_t dim, double const* ptr_data, Logger* pLogger);
    virtual IVector* clone() const = 0;
    
    virtual RC getCord(size_t index, double& val) const = 0;
    virtual RC setCord(size_t index, double val) = 0;
    virtual RC scale(double multiplier) = 0;
    virtual size_t dim() const = 0;

    static IVector* add(IVector const * op1, IVector const * op2, Logger* pLogger);
    static IVector* sub(IVector const * op1, IVector const * op2, Logger* pLogger);

    static double dot(IVector const * op1, IVector const * op2, Logger* pLogger);
    static bool equals(IVector const * op1, IVector const * op2, NORM n, double tol, Logger* pLogger);
    virtual double norm(NORM n) const = 0;

    virtual ~IVector() = 0;

private:
    IVector(const IVector& vector) = delete;
    IVector& operator=(const IVector& vector) = delete;

protected:
    IVector() = default;
};
