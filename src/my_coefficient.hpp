#ifndef MY_COEFFICIENT
#define MY_COEFFICIENT

#include <coefficient.hpp>


namespace ngfem
{
  
  /*
    CoefficientFunction which computes the eigenvalues of
    a symmetric 2x2 matrix-valued CoefficientFunction
  */
  class EigH_CF : public T_CoefficientFunction<EigH_CF>
  {
    shared_ptr<CoefficientFunction> mat;
  public:
    EigH_CF(shared_ptr<CoefficientFunction> _mat)
      : mat(_mat)
    {
      if (_mat->Dimensions() != Array<int> ({ 2, 2}))
        throw Exception("input must be a 2x2 matrix CF");

      // we return a 2-vector, so the shape is (2,)
      SetDimensions(Array<int>({2}));
    }


    // evaluates for all points of the integration rule ir
    // the function is generated for the generic types T,
    // and will be instantiated for 
    // double, complex, AutoDiff, SIMD<double>, ...
    template <typename MIR, typename T, ORDERING ORD>
    void T_Evaluate (const MIR & ir,
                     BareSliceMatrix<T,ORD> result) const
    {
      // create a temporary matrix on the stack
      STACK_ARRAY(T, hmem, 4*ir.Size());
      FlatMatrix<T,ORD> temp(4, ir.Size(), &hmem[0]);

      // evalute input coefficient function, a 2x2 matrix
      mat->Evaluate (ir, temp);

      for (size_t i = 0; i < ir.Size(); i++)
        {
          // matrix entries are [ [a,b], [b,c] ]
          T a = temp(0,i);
          T b = temp(1,i);
          T c = temp(3,i);

          result(0,i) = 0.5*(a+c) + sqrt ( 0.25*(a-c)*(a-c) + b*b );
          result(1,i) = 0.5*(a+c) - sqrt ( 0.25*(a-c)*(a-c) + b*b );
        }
    }

    // evaluates for all points of an integration rule
    // the input values are provided by caller
    template <typename MIR, typename T, ORDERING ORD>
    void T_Evaluate (const MIR & ir,
                     FlatArray<BareSliceMatrix<T,ORD>> input,                       
                     BareSliceMatrix<T,ORD> result) const
    {
      auto temp = input[0];
      for (size_t i = 0; i < ir.Size(); i++)
        {
          // matrix entries are [ [a,b], [b,c] ]          
          T a = temp(0,i);
          T b = temp(1,i);
          T c = temp(3,i);
          result(0,i) = 0.5*(a+c) + sqrt ( 0.25*(a-c)*(a-c) + b*b );
          result(1,i) = 0.5*(a+c) - sqrt ( 0.25*(a-c)*(a-c) + b*b );
        }
    }
  };
}



#endif

