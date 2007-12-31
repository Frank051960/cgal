// Copyright (c) 2001-2004  ENS of Paris (France).
// All rights reserved.
//
// This file is part of CGAL (www.cgal.org); you may redistribute it under
// the terms of the Q Public License version 1.0.
// See the file LICENSE.QPL distributed with CGAL.
//
// Licensees holding a valid commercial license may use this file in
// accordance with the commercial license agreement provided with the software.
//
// This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
// WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
//
// $URL$
// $Id$
//
// Author(s)     : Pierre Angelier, Michel Pocchiola

#ifndef CGAL_VISIBILITY_COMPLEX_2_MATROIDAL_ITEMS_H
#define CGAL_VISIBILITY_COMPLEX_2_MATROIDAL_ITEMS_H

#ifndef CGAL_VISIBILITY_COMPLEX_2_ITEMS_H
#include <CGAL/Visibility_complex_2/Items.h>
#endif

CGAL_BEGIN_NAMESPACE
namespace Visibility_complex_2_details {
// -----------------------------------------------------------------------------

template < class Vc_ >
class Matroidal_vertex
    : public Vertex_base<Vc_>
{
public:
    typedef Matroidal_vertex<Vc_>  Self;
    typedef Visibility_complex_2_details::Vertex_base<Vc_>  Vertex_base;
    typedef typename Vertex_base::Vertex_handle     Vertex_handle;
    typedef typename Vertex_base::Edge_handle       Edge_handle;
    typedef typename Vertex_base::Disk_handle    Disk_handle;
    typedef typename Vertex_base::Bitangent_2       Bitangent_2;
    typedef typename Vertex_base::Type              Type;

    Matroidal_vertex() {}
    Matroidal_vertex(Type t , Disk_handle start , 
				        Disk_handle finish) 
	: Vertex_base(t,start,finish) , phiR_(0) , phiL_(0) {}
    Matroidal_vertex(Edge_handle start , Edge_handle finish)
	: Vertex_base(start,finish) , phiR_(0) , phiL_(0)   {}
    Matroidal_vertex(const Bitangent_2& b) 
	: Vertex_base(b) , phiR_(0) , phiL_(0) {}
    Matroidal_vertex( const Vertex_base& v)   // down cast
        : Vertex_base(v) , phiR_(0) , phiL_(0) {}
/*     Self& operator=( const Self& v) { */
/*         this->Vertex_base::operator=(v); */
/*         phi_R_=v.phi_R_; */
/*         phi_L_=v.phi_L_; */
/*         return *this; */
/*     } */
    Edge_handle phiR() const { return phiR_; }
    void set_phiR(const Edge_handle& e) { phiR_ = e; }
    Edge_handle phiL() const { return phiL_; }
    void set_phiL(const Edge_handle& e) { phiL_ = e; }

    Vertex_handle phiR_vertex() const { return phiR_vertex_; }
    void set_phiR_vertex(const Vertex_handle& v) { phiR_vertex_ = v; }
    Vertex_handle phiL_vertex() const { return phiL_vertex_; }
    void set_phiL_vertex(const Vertex_handle& v) { phiL_vertex_ = v; }

private:
    Edge_handle phiR_,phiL_;
    Vertex_handle phiR_vertex_,phiL_vertex_;
};

// -----------------------------------------------------------------------------

class Matroidal_items 
: public Items {
public:
    template <class VCA>
    struct Vertex_wrapper {
	typedef Matroidal_vertex<VCA> Vertex;
    };
};

// -----------------------------------------------------------------------------
}
CGAL_END_NAMESPACE

#endif // CGAL_VISIBILITY_COMPLEX_2_MATROIDAL_ITEMS_H
