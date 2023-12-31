/* GNOME Button Control
 * Copyright (C) 2003-2004 Ronald Bultje <rbultje@ronald.bitfreak.net>
 *
 * button.h: flat toggle button with images
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#ifndef __GVC_BUTTON_H__
#define __GVC_BUTTON_H__

#include <glib.h>
#include <gtk/gtk.h>

G_BEGIN_DECLS

#define GNOME_VOLUME_CONTROL_TYPE_BUTTON \
  (gnome_volume_control_button_get_type ())
#define GNOME_VOLUME_CONTROL_BUTTON(obj) \
  (G_TYPE_CHECK_INSTANCE_CAST ((obj), GNOME_VOLUME_CONTROL_TYPE_BUTTON, \
			       GnomeVolumeControlButton))
#define GNOME_VOLUME_CONTROL_BUTTON_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_CAST ((klass), GNOME_VOLUME_CONTROL_TYPE_BUTTON, \
			    GnomeVolumeControlButtonClass))
#define GNOME_VOLUME_CONTROL_IS_BUTTON(obj) \
  (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GNOME_VOLUME_CONTROL_TYPE_BUTTON))
#define GNOME_VOLUME_CONTROL_IS_BUTTON_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_TYPE ((klass), GNOME_VOLUME_CONTROL_TYPE_BUTTON))

typedef struct _GnomeVolumeControlButton {
  GtkButton parent;

  /* stock icons */
  gchar *active_icon,
	*inactive_icon;

  /* state */
  gboolean active;

  /* image */
  GtkImage *image;
} GnomeVolumeControlButton;

typedef struct _GnomeVolumeControlButtonClass {
  GtkButtonClass klass;
} GnomeVolumeControlButtonClass;

GType		gnome_volume_control_button_get_type	(void);
GtkWidget *	gnome_volume_control_button_new		(gchar   *active_icon,
							 gchar   *inactive_icon,
							 gchar   *msg);
gboolean	gnome_volume_control_button_get_active	(GnomeVolumeControlButton *button);
void		gnome_volume_control_button_set_active	(GnomeVolumeControlButton *button,
							 gboolean active);

G_END_DECLS

#endif /* __GVC_BUTTON_H__ */
