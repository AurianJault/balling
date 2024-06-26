#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.h"
#include <cmath>

class sphere : public hittable{
  public:
    sphere(const point3& center,double radius) : center(center), radius(fmax(0,radius)) {}

    bool hit(const ray& r,interval ray_t, hit_record& rec) const override{
      vec3 oc = center - r.origin();

      auto a = r.direction().length_squared();
      auto h = dot(r.direction(),oc);
      auto c = oc.length_squared() - radius*radius;

      auto discriminant = h*h - a*c;

      if(discriminant < 0 ){
        return false;
      }

      auto sqrd = sqrt(discriminant);
      
      auto root = (h - sqrd) / a;
      if(!ray_t.surrounds(root)){
        root = (h + sqrd) / a;
        if(!ray_t.surrounds(root))
          return false;
      }
      
      rec.t = root;
      rec.p = r.at(rec.t);
      vec3 outward_normal = (rec.p - center) / radius;
      rec.set_face_normal(r, outward_normal);
      rec.normal = (rec.p - center) / radius;
      
      return true;
    }


  private:
    point3 center;
    double radius;
};

#endif // !SPHERE_H
