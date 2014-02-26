//
//  ml_regression.h
//  ml
//
//  Created by Jamie Bullock on 25/02/2014.
//
//

#ifndef ml_ml_regression_h
#define ml_ml_regression_h

#include "ml.h"

namespace ml
{
    class ml_regression : public ml
    {
        FLEXT_HEADER_S(ml_regression, ml, setup);
        
    public:
        ml_regression()
        {
            labelledRegressionData.setInputAndTargetDimensions(defaultNumInputDimensions, defaultNumOutputDimensions);
            set_data_type(LABELLED_REGRESSION);
        }
        
        ~ml_regression()
        {
            
        }
        
    protected:
        static void setup(t_classid c)
        {
            FLEXT_CADDATTR_SET(c, "max_iterations", set_max_iterations);
            FLEXT_CADDATTR_SET(c, "min_change", set_min_change);
            FLEXT_CADDATTR_SET(c, "training_rate", set_training_rate);
            
            FLEXT_CADDATTR_GET(c, "max_iterations", get_max_iterations);
            FLEXT_CADDATTR_GET(c, "min_change", get_min_change);
            FLEXT_CADDATTR_GET(c, "training_rate", get_training_rate);
        }
        
        // Methods
        void train();
        void map(int argc, const t_atom *argv);
        void usage();
        
        // Attribute Setters
        void set_max_iterations(int max_iterations);
        void set_min_change(float min_change);
        void set_training_rate(float training_rate);
        
        
        // Attribute Getters
        void get_max_iterations(int &max_iterations) const;
        void get_min_change(float &min_change) const;
        void get_training_rate(float &training_rate) const;
        
        virtual GRT::MLBase &get_MLBase_instance() final;
        virtual const GRT::MLBase &get_MLBase_instance() const final;
        
        virtual GRT::Regressifier &get_Regressifier_instance() = 0;
        virtual const GRT::Regressifier &get_Regressifier_instance() const = 0;
        
        bool load_specialised_data(std::string &path);
        
    private:
        
        // Method wrappers
        
        // Attribute wrappers
        FLEXT_CALLVAR_I(get_max_iterations, set_max_iterations);
        FLEXT_CALLVAR_F(get_min_change, set_min_change);
        FLEXT_CALLVAR_F(get_training_rate, set_training_rate);
    };
}

#endif
