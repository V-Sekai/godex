#pragma once

#include "../../databags/databag.h"
#include "core/templates/paged_allocator.h"
#include "shape_base.h"
#include <BulletCollision/CollisionShapes/btConeShape.h>

struct BtCone : public BtRigidShape {
	COMPONENT_CUSTOM_CONSTRUCTOR(BtCone, SharedSteadyStorage)

	static void _bind_methods();
	static void _get_storage_config(Dictionary &r_config);

	real_t radius = 1.0;
	real_t height = 1.0;
	real_t margin = 0.004;

	BtCone() :
			BtRigidShape(TYPE_CONE) {}

	void set_radius(real_t p_radius);
	real_t get_radius() const;

	void set_height(real_t p_height);
	real_t get_height() const;

	void set_margin(real_t p_margin);
	real_t get_margin() const;

	ShapeInfo *add_shape(btConeShape *p_shape, const Vector3 &p_scale);

private:
	void update_shapes();
};

struct BtShapeStorageCone : public godex::Databag {
	DATABAG(BtShapeStorageCone);

	PagedAllocator<btConeShape, false> allocator;

	btCollisionShape *construct_shape(BtCone *p_shape_owner, const Vector3 &p_scale);
};
