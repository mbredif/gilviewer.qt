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

#include <limits>

#include <boost/filesystem.hpp>

#include <wx/dcbuffer.h>
#include <wx/minifram.h>
#include <wx/button.h>
#include <wx/slider.h>
#include <wx/sizer.h>
#include <wx/msgdlg.h>
#include <wx/config.h>
#include <wx/log.h>
#include <wx/statusbr.h>
#include <wx/checkbox.h>
#include <wx/textctrl.h>
#include <wx/filepicker.h>
#include <wx/valtext.h>

#include "GilViewer/gui/PanelViewer.hpp"
#include "GilViewer/gui/LayerControl.hpp"
#include "GilViewer/gui/define_id.hpp"

#include "GilViewer/gui/ImageLayerSettingsControl.hpp"

ImageLayerSettingsControl::ImageLayerSettingsControl(unsigned int index, LayerControl* parent, wxWindowID id, const wxString& title, long style, const wxPoint& pos, const wxSize& size) :
	LayerSettingsControl(parent, id, title, pos, size, style), m_parent(parent)
{
	m_index = index;

	wxColour bgcolor( 220, 220, 220);
	SetBackgroundColour(bgcolor);
	ClearBackground();

	wxFlexGridSizer *main_sizer = new wxFlexGridSizer(4,1,0,0);
	main_sizer->AddGrowableCol(0);
	main_sizer->AddGrowableRow(0);

	m_histogramPanel = new HistogramPlotter(this, 0, 1, 2, wxID_ANY,wxDefaultPosition,wxSize(300,150));
	wxColour bgcolorpanel( 255, 255, 255);
	m_histogramPanel->SetBackgroundColour(bgcolorpanel);
	m_histogramPanel->ClearBackground();
	main_sizer->Add(m_histogramPanel, 1, wxEXPAND|wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5);

	// L'interface dépend du nombre de composantes
	m_nbComponents = m_parent->Layers()[index]->GetNbComponents();
	if (m_nbComponents == 1)
	{
		wxStaticBoxSizer *red_sizer = new wxStaticBoxSizer(wxHORIZONTAL,this,_("Channel"));
		wxString redMin;
		redMin << GetLayerControl()->Layers()[index]->IntensityMin();
		m_textRedMinimumIntensity = new wxTextCtrl(this,wxID_ANY,redMin);
		m_textRedMinimumIntensity->SetValidator(wxTextValidator(wxFILTER_NUMERIC));
		red_sizer->Add(m_textRedMinimumIntensity, 1, wxEXPAND|wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5);
		wxString redMax;
		redMax << GetLayerControl()->Layers()[index]->IntensityMax();
		m_textRedMaximumIntensity = new wxTextCtrl(this,wxID_ANY,redMax);
		m_textRedMaximumIntensity->SetValidator(wxTextValidator(wxFILTER_NUMERIC));
		red_sizer->Add(m_textRedMaximumIntensity, 1, wxEXPAND|wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5);
		m_textRedGamma = new wxTextCtrl(this,wxID_ANY,wxT("1"));
		m_textRedGamma->SetValidator(wxTextValidator(wxFILTER_NUMERIC));
		red_sizer->Add(m_textRedGamma, 1, wxEXPAND|wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5);
		main_sizer->Add(red_sizer, 1, wxEXPAND|wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5);

		//Choix de la LUT
		wxStaticBoxSizer *fileLUT_sizer = new wxStaticBoxSizer(wxHORIZONTAL,this,_("Choose LUT"));
		wxString str;
		wxConfigBase::Get()->Read(wxT("/Paths/LUT"), &str, ::wxGetCwd());
		m_filePicker_CLUT = new wxFilePickerCtrl(this, wxID_ANY, str, _("Select a CLUT file"), wxT("*.*"), wxDefaultPosition, wxDefaultSize, wxFLP_DEFAULT_STYLE);
		fileLUT_sizer->Add(m_filePicker_CLUT, 1, wxEXPAND|wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5);
		main_sizer->Add(fileLUT_sizer, 1, wxEXPAND|wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5);
	}
	else
	{
		wxStaticBoxSizer *red_sizer = new wxStaticBoxSizer(wxHORIZONTAL,this,_("Red"));
		m_textRedChannel = new wxTextCtrl(this,wxID_ANY);
		m_textRedChannel->SetValidator(wxTextValidator(wxFILTER_NUMERIC));
		m_textRedChannel->SetValue(wxT("0"));
		m_textRedChannel->SetToolTip(_("Image channel index to be displayed in red (e.g. 0 for RGB image)"));
		red_sizer->Add(m_textRedChannel, 1, wxEXPAND|wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5);
		m_textRedMinimumIntensity = new wxTextCtrl(this,wxID_ANY);
		m_textRedMinimumIntensity->SetValidator(wxTextValidator(wxFILTER_NUMERIC));
		wxString redMin;
		redMin << GetLayerControl()->Layers()[index]->IntensityMin();
		m_textRedMinimumIntensity->SetValue(redMin);
		m_textRedMinimumIntensity->SetToolTip(_("Minimum intensity"));
		red_sizer->Add(m_textRedMinimumIntensity, 1, wxEXPAND|wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5);
		m_textRedMaximumIntensity = new wxTextCtrl(this,wxID_ANY);
		m_textRedMaximumIntensity->SetValidator(wxTextValidator(wxFILTER_NUMERIC));
		wxString redMax;
		redMax << GetLayerControl()->Layers()[index]->IntensityMax();
		m_textRedMaximumIntensity->SetValue(redMax);
		m_textRedMaximumIntensity->SetToolTip(_("Maximum intensity"));
		red_sizer->Add(m_textRedMaximumIntensity, 1, wxEXPAND|wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5);
		m_textRedGamma = new wxTextCtrl(this,wxID_ANY);
		m_textRedGamma->SetValue(wxT("1"));
		m_textRedGamma->SetValidator(wxTextValidator(wxFILTER_NUMERIC));
		m_textRedGamma->SetToolTip(_("Gamma"));
		red_sizer->Add(m_textRedGamma, 1, wxEXPAND|wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5);
		main_sizer->Add(red_sizer, 1, wxEXPAND|wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5);

		wxStaticBoxSizer *green_sizer = new wxStaticBoxSizer(wxHORIZONTAL,this,_("Green"));
		m_textGreenChannel = new wxTextCtrl(this,wxID_ANY);
		m_textGreenChannel->SetValidator(wxTextValidator(wxFILTER_NUMERIC));
		m_textGreenChannel->SetValue(wxT("1"));
		m_textGreenChannel->SetToolTip(_("Image channel index to be displayed in green (e.g. 1 for RGB image)"));
		green_sizer->Add(m_textGreenChannel, 1, wxEXPAND|wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5);
		m_textGreenMinimumIntensity = new wxTextCtrl(this,wxID_ANY);
		m_textGreenMinimumIntensity->SetValidator(wxTextValidator(wxFILTER_NUMERIC));
		wxString greenMin;
		greenMin << GetLayerControl()->Layers()[index]->IntensityMin();
		m_textGreenMinimumIntensity->SetValue(greenMin);
		m_textGreenMinimumIntensity->SetToolTip(_("Minimum intensity"));
		m_textGreenMinimumIntensity->Enable(false);
		m_textGreenMinimumIntensity->SetEditable(false);
		green_sizer->Add(m_textGreenMinimumIntensity, 1, wxEXPAND|wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5);
		m_textGreenMaximumIntensity = new wxTextCtrl(this,wxID_ANY);
		m_textGreenMaximumIntensity->SetValidator(wxTextValidator(wxFILTER_NUMERIC));
		wxString greenMax;
		greenMax << GetLayerControl()->Layers()[index]->IntensityMax();
		m_textGreenMaximumIntensity->SetValue(greenMax);
		m_textGreenMaximumIntensity->SetToolTip(_("Maximum intensity"));
		m_textGreenMaximumIntensity->Enable(false);
		m_textGreenMaximumIntensity->SetEditable(false);
		green_sizer->Add(m_textGreenMaximumIntensity, 1, wxEXPAND|wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5);
		m_textGreenGamma = new wxTextCtrl(this,wxID_ANY);
		m_textGreenGamma->SetValidator(wxTextValidator(wxFILTER_NUMERIC));
		m_textGreenGamma->SetValue(wxT("1"));
		m_textGreenGamma->SetToolTip(_("Gamma"));
		m_textGreenGamma->Enable(false);
		m_textGreenGamma->SetEditable(false);
		green_sizer->Add(m_textGreenGamma, 1, wxEXPAND|wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5);
		main_sizer->Add(green_sizer, 1, wxEXPAND|wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5);

		wxStaticBoxSizer *blue_sizer = new wxStaticBoxSizer(wxHORIZONTAL,this,_("Blue"));
		m_textBlueChannel = new wxTextCtrl(this,wxID_ANY);
		m_textBlueChannel->SetValidator(wxTextValidator(wxFILTER_NUMERIC));
		m_textBlueChannel->SetValue(wxT("2"));
		m_textBlueChannel->SetToolTip(_("Image channel index to be displayed in blue (e.g. 2 for RGB image)"));
		blue_sizer->Add(m_textBlueChannel, 1, wxEXPAND|wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5);
		m_textBlueMinimumIntensity = new wxTextCtrl(this,wxID_ANY);
		m_textBlueMinimumIntensity->SetValidator(wxTextValidator(wxFILTER_NUMERIC));
		wxString blueMin;
		blueMin << GetLayerControl()->Layers()[index]->IntensityMin();
		m_textBlueMinimumIntensity->SetValue(blueMin);
		m_textBlueMinimumIntensity->SetToolTip(_("Minimum intensity"));
		m_textBlueMinimumIntensity->Enable(false);
		m_textBlueMinimumIntensity->SetEditable(false);
		blue_sizer->Add(m_textBlueMinimumIntensity, 1, wxEXPAND|wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5);
		m_textBlueMaximumIntensity = new wxTextCtrl(this,wxID_ANY);
		m_textBlueMaximumIntensity->SetValidator(wxTextValidator(wxFILTER_NUMERIC));
		wxString blueMax;
		blueMax << GetLayerControl()->Layers()[index]->IntensityMax();
		m_textBlueMaximumIntensity->SetValue(blueMax);
		m_textBlueMaximumIntensity->SetToolTip(_("Maximum intensity"));
		m_textBlueMaximumIntensity->Enable(false);
		m_textBlueMaximumIntensity->SetEditable(false);
		blue_sizer->Add(m_textBlueMaximumIntensity, 1, wxEXPAND|wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5);
		m_textBlueGamma = new wxTextCtrl(this,wxID_ANY);
		m_textBlueGamma->SetValidator(wxTextValidator(wxFILTER_NUMERIC));
		m_textBlueGamma->SetValue(wxT("1."));
		m_textBlueGamma->SetToolTip(_("Gamma"));
		m_textBlueGamma->Enable(false);
		m_textBlueGamma->SetEditable(false);
		blue_sizer->Add(m_textBlueGamma, 1, wxEXPAND|wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5);
		main_sizer->Add(blue_sizer, 1, wxEXPAND|wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5);

	}

	wxStaticBoxSizer *alpha_sizer = new wxStaticBoxSizer(wxVERTICAL,this,_("Alpha"));
	unsigned int alphaValue = GetLayerControl()->Layers()[index]->Alpha();
	m_alphaSlider = new wxSlider(this,wxID_ANY,alphaValue,0,255,wxDefaultPosition,wxDefaultSize,wxSL_LABELS);
	alpha_sizer->Add(m_alphaSlider, 1, wxEXPAND|wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5);
	//
	// On ajoute une checkBox et deux textControl pour saisir un range de valeurs auxquelles on applique la transparence
	// On met le check par defaut a false et on grise les textControl min et max
	m_checkAlphaRange = new wxCheckBox(this,ID_ALPHA_RANGE_CHECK,_("Transparency range"));
	m_checkAlphaRange->SetValue( false);
	m_checkAlphaRange->SetToolTip(_("Check to choose a transparency range"));
	m_textAlphaRangeMin = new wxTextCtrl( this , wxID_ANY );
	m_textAlphaRangeMin->SetValidator(wxTextValidator(wxFILTER_NUMERIC));
	m_textAlphaRangeMin->Enable(false);
	m_textAlphaRangeMin->SetEditable(false);
	m_textAlphaRangeMin->SetToolTip(_("Min transparency range"));
	m_textAlphaRangeMax = new wxTextCtrl( this , wxID_ANY );
	m_textAlphaRangeMax->SetValidator(wxTextValidator(wxFILTER_NUMERIC));
	m_textAlphaRangeMax->Enable(false);
	m_textAlphaRangeMax->SetEditable(false);
	m_textAlphaRangeMax->SetToolTip(_("Max transparency range"));
	// On les met dans un boxSizer horizontal, que l'on ajoute dans le boxSizer qui encapsule tout ce qui concerne la transparence
	wxStaticBoxSizer *alpha_range_sizer = new wxStaticBoxSizer(wxHORIZONTAL,this,_("Alpha range"));
	alpha_range_sizer->Add(m_checkAlphaRange, 1, wxEXPAND|wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5);
	alpha_range_sizer->Add(m_textAlphaRangeMin, 1, wxEXPAND|wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5);
	alpha_range_sizer->Add(m_textAlphaRangeMax, 1, wxEXPAND|wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5);
	alpha_sizer->Add(alpha_range_sizer, 1, wxEXPAND|wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5);

	//si plus d'une channel, possibilité de choisir une channel comme channel alpha
	if (m_nbComponents > 1)
	{
		m_checkAlphaChannel = new wxCheckBox(this,ID_ALPHA_CHANNEL_CHECK,_("Alpha channel"));
		m_checkAlphaChannel->SetValue( false);
		m_checkAlphaChannel->SetToolTip(_("Check to choose an alpha channel"));
		m_textAlphaChannel = new wxTextCtrl( this , wxID_ANY );
		m_textAlphaChannel->SetValidator(wxTextValidator(wxFILTER_NUMERIC));
		m_textAlphaChannel->Enable(false);
		m_textAlphaChannel->SetToolTip(_("Alpha channel number"));
		wxStaticBoxSizer *alpha_channel_sizer = new wxStaticBoxSizer(wxHORIZONTAL,this,_("Alpha channel"));
		alpha_channel_sizer->Add(m_checkAlphaChannel, 1, wxEXPAND|wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5);
		alpha_channel_sizer->Add(m_textAlphaChannel, 1, wxEXPAND|wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5);
		alpha_sizer->Add(alpha_channel_sizer, 1, wxEXPAND|wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5);
	}


	// On rajoute tout ce qui concerne la transparence dans le sizer principal
	main_sizer->Add(alpha_sizer, 1, wxEXPAND|wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_CENTER_HORIZONTAL, 5);

	wxStdDialogButtonSizer *buttons_sizer = new wxStdDialogButtonSizer();
	buttons_sizer->AddButton(new wxButton(this,wxID_OK, wxT("OK")));
	buttons_sizer->AddButton(new wxButton(this,wxID_APPLY, wxT("Apply")));
	buttons_sizer->AddButton(new wxButton(this,wxID_CANCEL, wxT("Cancel")));
	buttons_sizer->Realize();
	main_sizer->Add(buttons_sizer, 0, wxALIGN_RIGHT|wxALL, 5);

	//CreateStatusBar();
	//GetStatusBar()->SetStatusText(wxString(_("Status :")));

	main_sizer->SetSizeHints(this);
	SetSizer(main_sizer);
	Layout();
	Centre();
}

BEGIN_EVENT_TABLE(ImageLayerSettingsControl, wxDialog)
EVT_CLOSE(ImageLayerSettingsControl::OnCloseWindow)
EVT_BUTTON(wxID_OK,ImageLayerSettingsControl::OnOKButton)
EVT_BUTTON(wxID_CANCEL,ImageLayerSettingsControl::OnCancelButton)
EVT_BUTTON(wxID_APPLY,ImageLayerSettingsControl::OnApplyButton)
EVT_CHECKBOX(ID_ALPHA_RANGE_CHECK, ImageLayerSettingsControl::OnCheckAlphaRange)
EVT_CHECKBOX(ID_ALPHA_CHANNEL_CHECK, ImageLayerSettingsControl::OnCheckAlphaChannel)
EVT_SET_FOCUS(ImageLayerSettingsControl::OnGetFocus)
END_EVENT_TABLE()

void ImageLayerSettingsControl::OnApplyButton(wxCommandEvent &event)
{
	// Pour l'instant, on se concentre sur le canal RED ...
	wxString redMinLabel = m_textRedMinimumIntensity->GetValue();
	wxString redMaxLabel = m_textRedMaximumIntensity->GetValue();
	wxString redGammaLabel = m_textRedGamma->GetValue();
	wxString alphaRangeMinLabel = m_textAlphaRangeMin->GetValue();
	wxString alphaRangeMaxLabel = m_textAlphaRangeMax->GetValue();

	double redMinDouble, redMaxDouble, redGammaDouble;
	double alphaRangeMin, alphaRangeMax;
	if ( !redMinLabel.ToDouble(&redMinDouble) )
	{
		::wxMessageBox(_("Bad min value on red channel!"));
		return;
	}
	if ( !redMaxLabel.ToDouble(&redMaxDouble) )
	{
		::wxMessageBox(_("Bad max value on red channel!"));
		return;
	}
	if ( !redGammaLabel.ToDouble(&redGammaDouble) )
	{
		::wxMessageBox(_("Bad gamma value on red channel!"));
		return;
	}

	// On va dire que si l'un au moins des rangeMin ou rangeMax est valide, alors, c'est bon.
	// Si un seul est valide, on met l'autre a la meme valeur

	if ( m_nbComponents > 1)
	{
		wxString redChannelLabel = m_textRedChannel->GetValue();
		long redChannel;
		if ( !redChannelLabel.ToLong(&redChannel) )
		{
			::wxMessageBox(_("Bad value on red channel!"));
			return;
		}

		wxString greenChannelLabel = m_textGreenChannel->GetValue();
		long greenChannel;
		if ( !greenChannelLabel.ToLong(&greenChannel) )
		{
			::wxMessageBox(_("Bad value on green channel!"));
			return;
		}
		wxString blueChannelLabel = m_textBlueChannel->GetValue();
		long blueChannel;
		if ( !blueChannelLabel.ToLong(&blueChannel) )
		{
			::wxMessageBox(_("Bad value on blue channel!"));
			return;
		}

		GetLayerControl()->Layers()[m_index]->SetChannels(redChannel, greenChannel, blueChannel);
		m_histogramPanel->SetChannels(redChannel, greenChannel, blueChannel);
		m_histogramPanel->Refresh();

		//alpha channel
		if( m_checkAlphaChannel->IsChecked() )
		{
			wxString alphaChannelLabel = m_textAlphaChannel->GetValue();
			long alphaChannel;
			if ( !alphaChannelLabel.ToLong(&alphaChannel) )
			{
				::wxMessageBox(_("Bad value on alpha channel!"));
				return;
			}

			GetLayerControl()->Layers()[m_index]->SetAlphaChannel(true, alphaChannel);
		}
		else
			GetLayerControl()->Layers()[m_index]->SetAlphaChannel(false, 0);
	}

	if (m_checkAlphaRange->IsChecked() )
	{
		if ( !alphaRangeMinLabel.ToDouble(&alphaRangeMin) && !alphaRangeMaxLabel.ToDouble(&alphaRangeMax) )
		{
			::wxMessageBox(_("Bad min and max range values for transparency!"));
			return;
		}
		else
		{
			// Le min est valide, le max ne l'est pas ...
			if (alphaRangeMinLabel.ToDouble(&alphaRangeMin) && !alphaRangeMaxLabel.ToDouble(&alphaRangeMax) )
			{
				alphaRangeMax = alphaRangeMin;
				wxString mn;
				mn << alphaRangeMin;
				wxString mx;
				mx << alphaRangeMax;
				m_textAlphaRangeMin->SetValue(mn);
				m_textAlphaRangeMax->SetValue(mx);
			}
			if ( !alphaRangeMinLabel.ToDouble(&alphaRangeMin) && alphaRangeMaxLabel.ToDouble(&alphaRangeMax) )
			{
				alphaRangeMin = alphaRangeMax;
				wxString mn;
				mn << alphaRangeMin;
				wxString mx;
				mx << alphaRangeMax;
				m_textAlphaRangeMin->SetValue(mn);
				m_textAlphaRangeMax->SetValue(mx);
			}

			//			// Enfin, si le min est superieur au max, on inverse les valeurs ...
			//			if ( alphaRangeMin > alphaRangeMax )
			//			{
			//				double inv = alphaRangeMin;
			//				alphaRangeMin = alphaRangeMax;
			//				alphaRangeMax = inv;
			//				// ... et les textControl !
			//				wxString mn;
			//				mn << alphaRangeMin;
			//				wxString mx;
			//				mx << alphaRangeMax;
			//				m_textAlphaRangeMin->SetValue(mn);
			//				m_textAlphaRangeMax->SetValue(mx);
			//			}
		}
	}


	GetLayerControl()->Layers()[m_index]->Alpha(m_alphaSlider->GetValue() );

	// Si on est la, tout s'est bien passe ...
	GetLayerControl()->Layers()[m_index]->IntensityMin(redMinDouble);
	GetLayerControl()->Layers()[m_index]->IntensityMax(redMaxDouble);
	GetLayerControl()->Layers()[m_index]->Gamma(redGammaDouble);

	// La, il faut brancher le range pour la transparence : alphaRangeMin et alphaRangeMax
	if (m_checkAlphaRange->IsChecked() )
	{
		GetLayerControl()->Layers()[m_index]->IsTransparent(true);
		GetLayerControl()->Layers()[m_index]->TransparencyMin(alphaRangeMin);
		GetLayerControl()->Layers()[m_index]->TransparencyMax(alphaRangeMax);
	}
	else
		GetLayerControl()->Layers()[m_index]->IsTransparent(false);


	//Branchement du choix de la CLUT
	if(m_nbComponents == 1)
	{
		std::string fileLUT(m_filePicker_CLUT->GetPath().fn_str() );
		if(boost::filesystem::exists(fileLUT))
		{
			if ( boost::filesystem::basename(fileLUT) == "random" )
				GetLayerControl()->Layers()[m_index]->GetColorLookupTable()->createRandom();
			else
				GetLayerControl()->Layers()[m_index]->GetColorLookupTable()->LoadFromBinaryFile( fileLUT );
		}
		else
		{
			::wxLogMessage(_("LUT file does not exist!"));
		}
	}

	m_parent->GetPanelViewer()->GetLayerControl()->Layers()[m_index]->HasToBeUpdated(true);
	m_parent->GetPanelViewer()->Refresh();
}

void ImageLayerSettingsControl::update()
{
	Layer::ptrLayerType layer = m_parent->Layers()[m_index];
	wxString min, max, gamma;
	// Mise a jour pour le canal rouge (il y en a toujours un)
	min << layer->IntensityMin();
	m_textRedMinimumIntensity->SetValue(min);
	max << layer->IntensityMax();
	m_textRedMaximumIntensity->SetValue(max);
	gamma << layer->Gamma();
	m_textRedGamma->SetValue(gamma);

	// Si on a 3 composantes, on met aussi a jour les controles pour les canaux vert et bleu
	if (m_nbComponents == 3)
	{
		m_textGreenMinimumIntensity->SetValue(min);
		m_textGreenMaximumIntensity->SetValue(max);
		m_textGreenGamma->SetValue(gamma);

		m_textBlueMinimumIntensity->SetValue(min);
		m_textBlueMaximumIntensity->SetValue(max);
		m_textBlueGamma->SetValue(gamma);
	}

	if (layer->IsTransparent())
	{
		m_checkAlphaRange->SetValue(true);
		min.Clear();
		min << layer->TransparencyMin();
		m_textAlphaRangeMin->Enable(true);
		m_textAlphaRangeMin->SetValue(min);
		max.Clear();
		max << layer->TransparencyMax();
		m_textAlphaRangeMax->Enable(true);
		m_textAlphaRangeMax->SetValue(max);
	}

	m_alphaSlider->SetValue(layer->Alpha());

	bool useAlphaChannel;
	unsigned int alphaChannel;
	layer->GetAlphaChannel(useAlphaChannel,alphaChannel);
	if ( useAlphaChannel )
	{
		wxString alpha;
		alpha << alphaChannel;
		m_checkAlphaChannel->SetValue(true);
		m_textAlphaChannel->Enable(true);
		m_textAlphaChannel->SetValue(alpha);
	}
}

void ImageLayerSettingsControl::OnCheckAlphaRange(wxCommandEvent &event)
{
	bool chk = event.IsChecked();

	m_textAlphaRangeMin->Enable(chk);
	m_textAlphaRangeMin->SetEditable(chk);
	m_textAlphaRangeMax->Enable(chk);
	m_textAlphaRangeMax->SetEditable(chk);
}

void ImageLayerSettingsControl::OnCheckAlphaChannel(wxCommandEvent &event)
{
	bool chk = event.IsChecked();

	m_textAlphaChannel->Enable(chk);
}

void ImageLayerSettingsControl::OnOKButton(wxCommandEvent &event)
{
	// On ne fait que cacher ...
	OnApplyButton(event);
	Hide();
}

void ImageLayerSettingsControl::OnCancelButton(wxCommandEvent &event)
{
	Hide();
}

void ImageLayerSettingsControl::OnSize(wxSizeEvent &event)
{
	m_histogramPanel->Refresh();
}

void ImageLayerSettingsControl::OnCloseWindow(wxCloseEvent& event)
{
	Hide();
}

void ImageLayerSettingsControl::OnGetFocus(wxFocusEvent &event)
{
	//Pour recharger les valeurs des parametres quand la fenetre reprend le focus
	wxString valueIntensityMin;
	valueIntensityMin<<GetLayerControl()->Layers()[m_index]->IntensityMin();
	m_textRedMinimumIntensity->SetValue(valueIntensityMin);

	wxString valueIntensityMax;
	valueIntensityMin<<GetLayerControl()->Layers()[m_index]->IntensityMax();
	m_textRedMaximumIntensity->SetValue(valueIntensityMax);

}

BEGIN_EVENT_TABLE(HistogramPlotter,wxPanel)
EVT_PAINT(HistogramPlotter::OnPaint)
EVT_SIZE(HistogramPlotter::OnSize)
EVT_MOTION(HistogramPlotter::OnMouseMove)
END_EVENT_TABLE()

HistogramPlotter::HistogramPlotter(ImageLayerSettingsControl* parent,  const unsigned int redChannel, const unsigned int greenChannel, const unsigned int blueChannel, wxWindowID id, const wxPoint& pos, const wxSize& size, long style) :
	wxPanel(parent, id, pos, size, style), m_parent(parent), m_isInit(false)
{
	SetChannels(redChannel, greenChannel, blueChannel);
}

void HistogramPlotter::OnMouseMove(wxMouseEvent &event)
{
	if (m_isInit)
	{

		//on teste si l'histogramme a bien été calculé sur le canal 0, sinon on quitte
		if(m_histogram[0].begin() == m_histogram[0].end())
			return;

		int width, height;
		this->GetClientSize(&width, &height);

		unsigned int window_width = static_cast<unsigned int>(width) - static_cast<unsigned int>(HISTOGRAM_LEFT_MARGIN) - static_cast<unsigned int>(HISTOGRAM_RIGHT_MARGIN);
		//unsigned int window_height = static_cast<unsigned int>(height) - static_cast<unsigned int>(HISTOGRAM_UP_MARGIN) - static_cast<unsigned int>(HISTOGRAM_BOTTOM_MARGIN);
		double step_width = window_width / static_cast<double>(m_histogram[0].size()-1.);

		/*
		 // Marche pô !!!
		 dc.SetPen( *wxBLACK_PEN );
		 dc.CrossHair(event.m_x,event.m_y);
		 wxString text;
		 text << event.m_x << " - " << event.m_y;
		 m_parent->GetStatusBar()->SetStatusText( text );
		 */

		const float nb_bins = static_cast<float>( m_histogram[0].size() - 1. );

		wxString text;
		if (event.m_x < static_cast<int>(HISTOGRAM_LEFT_MARGIN) || event.m_x > width-static_cast<int>(HISTOGRAM_RIGHT_MARGIN) )
			text << _("out!");
		else
		{
			//coordonnee entiere en nb_bins dans le tableau d'histo
			int coordXInt = static_cast<int>( (event.m_x - static_cast<int>(HISTOGRAM_LEFT_MARGIN))/ step_width );

			//coordonnee reelle en x dans la courbe d'histo
			float coordX = m_min + (m_max-m_min) / nb_bins * static_cast<float>( coordXInt );

			if (m_histogram.size() == 1)
				text << coordX << wxT(" - ") << m_histogram[0][ coordXInt ];
			else
			{
				text << coordX << _(" - Image = (");
				for(unsigned int channel = 0; channel < m_histogram.size(); ++channel)
				{
					text << channel << wxT(":") << m_histogram[channel][ coordXInt ];
					if(channel != m_histogram.size()-1)
						text << wxT(",");
				}
				text << wxT(")");
			}
		}
		m_parent->SetTitle( text );
		//m_parent->GetStatusBar()->SetStatusText(text);
	}
}

void HistogramPlotter::OnPaint(wxPaintEvent &event)
{
	if (m_isInit)
	{
		wxBufferedPaintDC dc(this);
		if (!dc.Ok())
			return;
		dc.Clear();

		int width, height;
		this->GetClientSize(&width, &height);



		//on teste si l'histogramme a bien été calculé sur le canal 0, sinon on quitte
		if(m_histogram[0].begin() == m_histogram[0].end())
			return;

		unsigned int window_width = static_cast<unsigned int>(width) - static_cast<unsigned int>(HISTOGRAM_LEFT_MARGIN) - static_cast<unsigned int>(HISTOGRAM_RIGHT_MARGIN);
		unsigned int window_height = static_cast<unsigned int>(height) - static_cast<unsigned int>(HISTOGRAM_UP_MARGIN) - static_cast<unsigned int>(HISTOGRAM_BOTTOM_MARGIN);
		double step_width = window_width / static_cast<double>(m_histogram[0].size()-1.);

		// On distingue les cas 1 et n canaux (on suppose pour l'instant n=3 ...)
		if (m_histogram.size() == 1)
		{
			dc.SetPen( *wxBLACK_PEN);
			double max_value = *std::max_element(m_histogram[0].begin(), m_histogram[0].end());
			double min_value = *std::min_element(m_histogram[0].begin(), m_histogram[0].end());
			double step_height = window_height / static_cast<double>(max_value-min_value);

			wxString min_string, max_string;
			min_string << min_value;
			max_string << max_value;
			dc.DrawText(min_string, static_cast<wxCoord>(HISTOGRAM_LEFT_MARGIN) , static_cast<wxCoord>(window_height)+static_cast<wxCoord>(HISTOGRAM_BOTTOM_MARGIN) );
			dc.DrawText(max_string, static_cast<wxCoord>(HISTOGRAM_LEFT_MARGIN) , static_cast<wxCoord>(HISTOGRAM_UP_MARGIN) );

			unsigned int i;
			for (i=0; i<m_histogram[0].size()-1; i++)
				dc.DrawLine( static_cast<unsigned int>(HISTOGRAM_LEFT_MARGIN)+i*step_width, static_cast<double>(window_height)-step_height*m_histogram[0][i]
						+static_cast<unsigned int>(HISTOGRAM_UP_MARGIN) , static_cast<unsigned int>(HISTOGRAM_LEFT_MARGIN)+(i+1)*step_width, static_cast<double>(window_height)-step_height
						*m_histogram[0][i+1]+static_cast<unsigned int>(HISTOGRAM_UP_MARGIN) );
		}
		else //nombre de canaux quelconque
		{
			// On calcule l'etendue maximale. On a donc besoin du min des min des n canaux et du max des max des n canaux.
			double	max_value = std::numeric_limits<double>::min();
			double min_value = std::numeric_limits<double>::max();
			for(unsigned int channel = 0; channel < m_histogram.size(); ++channel)
			{
				max_value = std::max( max_value, *std::max_element(m_histogram[channel].begin(), m_histogram[channel].end()) );
				min_value = std::min( min_value, *std::min_element(m_histogram[channel].begin(), m_histogram[channel].end()) );
			}

			double step_height = static_cast<double>(window_height) / (max_value - min_value);

			unsigned int i;

			//on affiche en RGB les canaux qui sont respectivement affichés en RGB dans l'image, et en noir les autres
			for(unsigned int channel = 0; channel < m_histogram.size(); ++channel)
			{
				//choix de la couleur
				if(channel == m_redChannel)
					dc.SetPen( *wxRED_PEN);
				else if(channel == m_greenChannel)
					dc.SetPen( *wxGREEN_PEN);
				else if(channel == m_blueChannel)
					dc.SetPen( wxPen( wxColour(0,0,255) ) );
				else
					dc.SetPen( *wxBLACK_PEN );

				//affichage de l'histo
				for (i=0; i<m_histogram[channel].size()-1; i++)
					dc.DrawLine( static_cast<unsigned int>(HISTOGRAM_LEFT_MARGIN)+i*step_width, static_cast<double>(window_height)-step_height*m_histogram[channel][i]
							+static_cast<unsigned int>(HISTOGRAM_UP_MARGIN) , static_cast<unsigned int>(HISTOGRAM_LEFT_MARGIN)+(i+1)*step_width, static_cast<double>(window_height)-step_height
							*m_histogram[channel][i+1]+static_cast<unsigned int>(HISTOGRAM_UP_MARGIN) );

			}

		}
	}
	else
	{
		wxBufferedPaintDC dc(this);
		if (!dc.Ok())
		return;
		dc.Clear();

		dc.DrawText( _("In progress ...") , 15 , 15 );

		ThreadHistogram *thread = new ThreadHistogram(m_parent);

		if ( thread->Create() != wxTHREAD_NO_ERROR )
		wxLogError(_("Can't create thread to compute image histogram!"));

		thread->Run();
	}
}

void HistogramPlotter::OnSize(wxSizeEvent &event)
{
	Refresh();
}

ThreadHistogram::ThreadHistogram(ImageLayerSettingsControl *parent) :
	wxThread()
{
	m_count = 0;
	m_parent = parent;
}

void ThreadHistogram::OnExit()
{
	m_parent->GetHistogramPlotter()->IsInit(true);
	m_parent->GetHistogramPlotter()->Refresh();
}

void *ThreadHistogram::Entry()
{
	m_parent->GetLayerControl()->Layers()[m_parent->Index()]->Histogram(m_parent->GetHistogramPlotter()->Data(), m_parent->GetHistogramPlotter()->Min(), m_parent->GetHistogramPlotter()->Max() );

	return NULL;
}
