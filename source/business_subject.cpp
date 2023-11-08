#include "../headers/business_subject.h"

float BusinessSubject::randomRating()const 
{
    
    return ((float)rand()/(RAND_MAX));
}

float BusinessSubject::getRating() const
{
    return this->m_rating;
}

std::string BusinessSubject::getBusinessName() const
{
    return this->m_businessName;
}
