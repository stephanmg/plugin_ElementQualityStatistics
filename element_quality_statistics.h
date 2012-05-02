/*
 * element_quality_statistics.cpp
 *
 *  Created on: 17.04.2012
 *      Author: Martin Stepniewski
 */


#ifndef __ElementQualityStatistics_h__
#define __ElementQualityStatistics_h__

/* system includes */
#include <stddef.h>
#include <cmath>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

#include "lib_grid/lib_grid.h"
#include "volume_calculation.h"



using namespace std;


namespace ug {


////////////////////////////////////////////////////////////////////////////////////////////
//	CollectAssociatedSides
////////////////////////////////////////////////////////////////////////////////////////////

///	Collects all edges (= 2) which exist in the given face and which share the given vertex.
UG_API
inline void CollectAssociatedSides(EdgeBase* sidesOut[2], Grid& grid, Face* f, VertexBase* vrt);

///	Collects all faces (= 2) which exist in the given volume and which share the given edge.
UG_API
inline void CollectAssociatedSides(Face* sidesOut[2], Grid& grid, Volume* v, EdgeBase* e);






////////////////////////////////////////////////////////////////////////////////////////////
//	CalculateMinFaceAngle
template <class TAAPosVRT>
number CalculateMinFaceAngle(Grid& grid, Face* f, TAAPosVRT& aaPos);


////////////////////////////////////////////////////////////////////////////////////////////
//	CalculateMinVolumeAngle
template <class TAAPosVRT>
number CalculateMinVolumeAngle(Grid& grid, Volume* v, Grid::VertexAttachmentAccessor<APosition>& aaPos);


////////////////////////////////////////////////////////////////////////////////////////////
//	CalculateMinTriangleHeight
template <class TAAPosVRT>
number CalculateMinTriangleHeight(Triangle* tri, TAAPosVRT& aaPos);


////////////////////////////////////////////////////////////////////////////////////////////
//	CalculateAspectRatio

//	An unimplemented version, so that a compile error occurs if no overload exists.
template <class TElem, class TAAPosVRT>
number CalculateAspectRatio(Grid& grid, TElem*, TAAPosVRT& aaPos);

//	Face (Triangles and Quadrilaterals)
template <class TAAPosVRT>
number CalculateAspectRatio(Grid& grid, Face* face, TAAPosVRT& aaPos);

//	Tetrahedron
template <class TAAPosVRT>
number CalculateAspectRatio(Grid& grid, Tetrahedron* tet, TAAPosVRT& aaPos);

//	Prism
template <class TAAPosVRT>
number CalculateAspectRatio(Grid& grid, Prism* prism, TAAPosVRT& aaPos);

//	Pyramid
template <class TAAPosVRT>
number CalculateAspectRatio(Grid& grid, Pyramid* pyr, TAAPosVRT& aaPos);

//	Volume
template <class TAAPosVRT>
number CalculateAspectRatio(Grid& grid, Volume* vol, TAAPosVRT& aaPos);




////////////////////////////////////////////////////////////////////////////////////////////
//	FindFaceWithSmallestMinAngle
template <class TIterator, class TAAPosVRT>
Face* FindFaceWithSmallestMinAngle(Grid& grid, 	TIterator volumesBegin,
												TIterator volumesEnd, TAAPosVRT& aaPos);


////////////////////////////////////////////////////////////////////////////////////////////
//	FindVolumeWithSmallestMinAngle
template <class TIterator, class TAAPosVRT>
Volume* FindVolumeWithSmallestMinAngle(Grid& grid, 	TIterator volumesBegin,
													TIterator volumesEnd, TAAPosVRT& aaPos);


////////////////////////////////////////////////////////////////////////////////////////////
//	FindLargestFace
template <class TIterator, class TAAPosVRT>
Face* FindLargestFace(TIterator facesBegin, TIterator facesEnd, TAAPosVRT& aaPos);


////////////////////////////////////////////////////////////////////////////////////////////
//	FindSmallestVolume
template <class TIterator, class TAAPosVRT>
Volume* FindSmallestVolume(TIterator volumesBegin, TIterator volumesEnd, TAAPosVRT& aaPos);


////////////////////////////////////////////////////////////////////////////////////////////
//	FindLargestVolume
template <class TIterator, class TAAPosVRT>
Volume* FindLargestVolume(TIterator volumesBegin, TIterator volumesEnd, TAAPosVRT& aaPos);


////////////////////////////////////////////////////////////////////////////////////////////
//	FindElementWithSmallestAspectRatio
template <class TIterator, class TAAPosVRT>
typename TIterator::value_type
FindElementWithSmallestAspectRatio(Grid& grid, 	TIterator volumesBegin,
												TIterator volumesEnd, TAAPosVRT& aaPos);


////////////////////////////////////////////////////////////////////////////////////////////
//	FindElementWithLargestAspectRatio
template <class TElem, class TIterator, class TAAPosVRT>
typename TIterator::value_type
FindElementWithLargestAspectRatio(Grid& grid, 	TIterator volumesBegin,
												TIterator volumesEnd, TAAPosVRT& aaPos);






////////////////////////////////////////////////////////////////////////////////////////////
//	MinFaceAngleHistogram
void MinFaceAngleHistogram(Grid& grid);


////////////////////////////////////////////////////////////////////////////////////////////
//	MinFaceAngleHistogram
void MinVolumeAngleHistogram(Grid& grid);






////////////////////////////////////////////////////////////////////////////////////////////
//	element_quality_statistics
void ElementQualityStatistics(Grid& grid);




}	 
#endif

