#pragma once

#include <vector>
#include <memory>

#include "hittable.h"

class HittableList : public Hittable {
public:
    HittableList();

    HittableList(std::shared_ptr<Hittable> object);

    void clear();
    void add(std::shared_ptr<Hittable> object);
    bool hit(const Ray& r, double t_min, double t_max, HitRecord& rec) const final;

    std::vector<std::shared_ptr<Hittable>> objects;
};
