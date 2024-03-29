/***********************************************************************

This file is part of the GilViewer project source files.

GilViewer is an open source 2D viewer (raster and vector) based on Boost
GIL and wxWidgets.


Homepage:

	http://code.google.com/p/gilviewer

Copyright:

	Institut Geographique National (2009)

Authors:

	Olivier Tournaire, Adrien Chauve




    GilViewer is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published
    by the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    GilViewer is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with GilViewer.  If not, see <http://www.gnu.org/licenses/>.

***********************************************************************/
#include "GilViewer/layers/image_types.hpp"

struct histogram_functor
{
    typedef void result_type;
    histogram_functor( std::vector< std::vector<double> > &histo , const double mini , const double maxi ) : m_histo(histo)
    {
        m_scale = 255. / (maxi-mini);
        m_offset = -mini * m_scale;
    }

    template <typename ViewType>
    typename boost::enable_if< boost::mpl::contains< boost::mpl::transform<gray_image_types,add_view_type<boost::mpl::_1> >::type,
    ViewType>,
    result_type>::type operator()(const ViewType& v) const
    {
        typename ViewType::iterator it_begin = v.begin(), it_end = v.end();
        for (; it_begin!=it_end; ++it_begin)
            ++m_histo[0][ boost::gil::at_c<0>(*it_begin)*m_scale+m_offset ];
    }

    template<class ViewType>
    typename boost::enable_if< boost::mpl::or_< boost::mpl::contains< boost::mpl::transform< rgb_image_types,
    add_view_type<boost::mpl::_1 > >::type,
    ViewType>,
    boost::mpl::contains< boost::mpl::transform< rgba_image_types,
    add_view_type<boost::mpl::_1 > >::type,
    ViewType>
    >,
    result_type>::type operator()(const ViewType& v) const
    {
        typename ViewType::iterator it_begin = v.begin(), it_end = v.end();
        for (; it_begin!=it_end; ++it_begin)
        {
            ++m_histo[0][ boost::gil::at_c<0>(*it_begin)*m_scale+m_offset];
            ++m_histo[1][ boost::gil::at_c<1>(*it_begin)*m_scale+m_offset];
            ++m_histo[2][ boost::gil::at_c<2>(*it_begin)*m_scale+m_offset];
        }
    }

    std::vector< std::vector<double> >& m_histo;
    double m_scale;
    double m_offset;
};
